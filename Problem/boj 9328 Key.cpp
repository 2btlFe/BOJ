/*
boj 9328 Key
Algorithm: BFS
Time_Complexity: O(T*H*W)
Explaination:
두 개의 저장소를 쓴다는 개념을 알아낸 건 잘했다
하지만, 아직까지 구현을 제대로 푸는 방법을 모르는 것 같다
구현 실력만 늘려도 좋을 것 같다

새로 얻은 지식
1. memset은 이차원 배열도 다 초기화시켜준다
2. 구현의 경우, init을 따로 만들어 주는 것이 좋다
3. 가장자리에서 침투하는 문제는 가장자리만 골라서 bfs를 쓰려고 하면
가장자리의 상태도 확인해야 하므로, 상태 확인을 중복해서 써야 한다
여기서는 (1,1) 부터 (h,w)까지 값을 넣어주고 나머지는 0으로 초기화 해서

(0,0)을 줌으로써 가장자리 침투가 가능하게 해줬다
이런 기법은 DP에도 많이 쓰인다. 
잘 알아두자 
*/


#include <bits/stdc++.h>

using namespace std;

const int INF = 111;
int d4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char board[INF][INF];
bool visited[INF][INF]; 
bool key[26];
int h, w, answer;
string FirstKey;

void init() {
    memset(board, 0, sizeof(board));    //이렇게 가능 
    memset(visited, false, sizeof(visited));
    memset(key, false, sizeof(key));
    FirstKey = "";
    answer = 0;
}

void bfs(int x, int y) {
    queue<pair<int, int> > Doors[26];
    queue<pair<int, int> > Q;
    Q.push({x, y});
    visited[x][y] = true;
    
    while(!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
      
        for(int i = 0; i < 4; i++) {
            int nr = r + d4[i][0];
            int nc = c + d4[i][1];
            if(nr < 0 || nr > h + 1 || nc < 0 || nc > w+1 || board[nr][nc] == '*' || visited[nr][nc] == true) continue;
            
            visited[nr][nc] = true;
            
            if(board[nr][nc] >= 'A' && board[nr][nc] <= 'Z') {
                int alpha = board[nr][nc] - 'A';
                if(key[alpha] == true) {
                    Q.push({nr, nc});    
                } else {
                    Doors[alpha].push({nr, nc});
                }
            } else if(board[nr][nc] >= 'a' && board[nr][c] <= 'z') {
                int alpha = board[nr][nc] - 'a';
                Q.push({nr, nc});
                if(key[alpha] == false) {
                    key[alpha] = true;
                    
                    while(!Doors[alpha].empty()) {
                        Q.push(Doors[alpha].front()); 
                        Doors[alpha].pop();
                    }
                }
            } else {  
                Q.push({nr, nc});
                if(board[nr][nc] == '$') answer++;
            } 
        }
    }
}

int main() {
  	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
    int t; cin >> t;
    vector<int> Answer;
    while(t--) {
        init();
        cin >> h >> w;
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                cin >> board[i][j];
            }
        }
        
        
        cin >> FirstKey;
        for(char c : FirstKey) {
            if(c == '0') continue;
            key[c - 'a'] = true;
        }
        
        bfs(0, 0);
        Answer.push_back(answer);
    }
    for(int ans : Answer) cout << ans << "\n";
}
