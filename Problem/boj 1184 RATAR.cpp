/*
boj 1184 귀농
Algorithm: prefix_sum, hash
TC: O(n^4)
SC: O(n^2)
Explaination:
indexing 이 어려웠다
일단 손으로 풀고 그 다음에 넣는 식으로 해야겠다
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;


void solve() {
    int N; cin >> N;
    vector<vector<int> > v(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int x; cin >> x;
            v[i][j] = x;
        }
    }
    
    vector<vector<int> > pre(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + v[i][j];
        }
    }
    
    int ret = 0;
    //1번째
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            
            map<int, int> m1, m2;
            for(int a = i+1; a <= N; a++) {
                for(int b = j+1; b <= N; b++) {
                    
                    int sum = pre[a][b] - pre[a][j] - pre[i][b] + pre[i][j];
                    m1[sum]++;
                }
            }
            
            
            for(int c = 0; c <= i-1; c++) {
                for(int d = 0; d <= j-1; d++) {
                    int sum = pre[i][j] - pre[c][j] - pre[i][d] + pre[c][d];
                    m2[sum]++;
                }
            }
            
            for(auto it = m1.begin(); it != m1.end(); it++) {
                if(m2.count((*it).first) != 0) {
                    //cout << (*it).first << " " << (*it).second << " " <<m2[((*it).first)] << endl;
                    ret += ((*it).second) * m2[((*it).first)];
                }
            }
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            map<int, int> m1, m2;
            for(int a = 0; a <= i -2; a++) {
                for(int b = j+1; b <= N; b++) {
                    int sum = pre[i-1][b] - pre[a][b] - pre[i-1][j] + pre[a][j];
                    m1[sum]++;
                }
            }
            
            for(int c = 0; c <= j-1; c++) {
                for(int d = i; d <= N; d++) {
                    int sum = pre[d][j] -pre[d][c] - pre[i-1][j]+ pre[i-1][c];
                    m2[sum]++;
                }
            }
   
            for(auto it = m1.begin(); it != m1.end(); it++) {
                if(m2.count((*it).first) != 0) {
                    //cout << (*it).first << " " << (*it).second << " " <<m2[((*it).first)] << endl;
                    ret += ((*it).second) * m2[((*it).first)];
                }
            }
        }
    }
    
    
    
    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
