/*
boj 9466 Term Project
Algorithm: SCC(DFS) or Topology_Sort
TC: O(N)
SC: O(N)
Explaination:

나는 문제를 보고 SCC를 생각해서
scc의 개수가 1인 집합의 숫자가
자기 자신을 가리키지 않은 경우를 세주었다

TC 분석
N = 10^5
V = 10^5, E = 10^5

너무 많이 재귀를 써서 그런가..?

588ms 나옴 -> 5*10^7 ms

*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

const int MXN = 1e5;

vector<int> adj(MXN+1);
vector<int> discovered, sccId;
int nodeCounter, sccCounter;

int ans;
stack<int> st;

int scc(int here) {
    int ret = discovered[here] = nodeCounter++;
    st.push(here);
    
    int there = adj[here];
    if(discovered[there] == -1) {
        ret = min(ret, scc(there));
    } else if(sccId[there] == -1) {
        ret = min(ret, discovered[there]);
    }
    
    if(ret == discovered[here]) {
        int cnt = 0;
        while(1) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            cnt++;
            if(t == here) {
                if(cnt == 1 && (t != adj[t])) {
                    ans++;
                }
                break;
            }
        }
        sccCounter++;
    }
    return ret;
}

void makeSCC(int n) {
    discovered = sccId = vector<int>(n + 1, -1);
    nodeCounter = sccCounter = 0;
    for(int i = 1; i <= n; i++) {
        if(discovered[i] == -1) scc(i); 
    }
    return;
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        adj[i] = x;
    }
    ans = 0;
    makeSCC(n);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
