/*
boj 17143 FishKing
Algorithm: implementation
TC: O(N^3)
SC: O(N^2)
Explaination:
그냥 구현이다
테스트 코드를 적고 하면 오히려 더 빠를 것 같다
모든 배열을 출력하는 게 있으면 
보기에 편해서 좋다 
*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int R, C, M;

struct shark{
    bool isDeleted;
    int  speed, axis, orient, z;
    vector<int> pos;
    
    shark(int r, int c, int s, int d, int zz) {
        pos.resize(2);
        pos[0] = r;
        pos[1] = c;
        speed = s;
        switch(d) {
            case 1: {
                axis = 0;
                orient = -1;
                break;
            } 
            case 2: {
                axis = 0;
                orient = 1;
                break;
            }
            case 3: {
                axis = 1;
                orient = 1;
                break;
            }
            case 4: {
                axis = 1;
                orient = -1;
                break;
            }
        }
        z = zz;
        isDeleted = false;        
    }
    
    vector<int> nextPos() {
        int l = 1, r = (axis == 0 ? R : C);
        int rawPos = pos[axis] + orient*speed;
        if(l <= rawPos && rawPos <= r) {
            pos[axis] += orient*speed;
            return pos;
        }
        
        int rest = speed - (orient == -1 ? (pos[axis] - l) : (r - pos[axis]));
        if(rest/(r-1)%2 == 0) orient *= -1;
        
        pos[axis] = rest%(r-1)*orient + (orient == -1 ? r : l);    
        return pos;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> R >> C >> M;
    
    vector<vector<int> > board(R+1, vector<int>(C+1, -1));
    vector<shark> v;
    for(int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = i;
        shark s_input(r, c, s, d, z);
        v.push_back(s_input);
    }
    
    //check(v, board);
    int ret = 0;
    for(int i = 1; i <= C; i++) {
        for(int j = 1; j <= R; j++) {
            if(board[j][i] != -1) {
                ret += v[board[j][i]].z;
                v[board[j][i]].isDeleted = true;
                board[j][i] = -1;
                break;
            }
        }
        
        vector<vector<int> > tmp(R+1, vector<int>(C+1, -1));
        for(int k = 0; k < M; k++) {
            if(v[k].isDeleted) continue;
            
            vector<int> np = v[k].nextPos();
            if(tmp[np[0]][np[1]] == -1) {
                tmp[np[0]][np[1]] = k;
            } else {
                int cand = tmp[np[0]][np[1]];
                if(v[k].z > v[cand].z) {
                    v[cand].isDeleted = true;
                    tmp[np[0]][np[1]] = k;
                } else {
                    v[k].isDeleted = true;
                }
            }
        }    
        board = tmp;
        //cout << ret << endl;
        //check(v, board);
    }

    cout << ret << endl;
}
