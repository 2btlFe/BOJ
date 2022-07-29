/*
boj 3176 Road Network
Algorithm: LCA, Sparse_Table
Time_Complexity: O(NlogN)
Explain: 
LCA를 최솟값, 최댓값 구할 때도 쓸 수 있다
처음에 틀릴 때는 로직을 잘 이해하지 못해서 틀렸고, 
두번째 틀릴 때는 N을 잘 못 적어서 틀렸고
마지막으로 틀릴 때는 d를 -1로 초기화 하지 않아서 틀렸다

꼭 다음엔 맞추자
*/

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int INF = 987654321;
const int MAX_N = 100001;
const int lg = 20;
int N, K;
vector<pair<int, int> > adj[MAX_N];
int d[MAX_N];
int parent[MAX_N][lg];
int qmin[MAX_N][lg];
int qmax[MAX_N][lg];

void dfs(int here) {
    for(auto p : adj[here]) {
        int there = p.first;
        int dist = p.second;
        
        if(d[there] != -1) continue;
        d[there] = d[here] + 1;
        parent[there][0] = here;
        qmin[there][0] = dist;
        qmax[there][0] = dist;
        dfs(there);
    }
}

pair<int, int> lca(int u, int v) {
    int rmin = INF;
    int rmax = -INF;
    
    //1. 더 깊은 노드를 끌어올려 깊이를 일치시킨다
    if(d[u] < d[v]) swap(u, v);
    for(int i = lg - 1; i >= 0; i--) {
        if(d[parent[u][i]] >= d[v]) {
            rmin = min(rmin, qmin[u][i]);
            rmax = max(rmax, qmax[u][i]);
            u = parent[u][i];
        }
    }

    //2. 깊이가 같은 상황에서 같은 노드라면 skip, 다른 노드라면 같이 올린다 같아지면 끝이다. 
    if(u != v) {
        for(int i = lg - 1; i >= 0; i--) {
            if(parent[u][i] != parent[v][i]) {
                rmin = min({rmin, qmin[u][i], qmin[v][i]});
                rmax = max({rmax, qmax[u][i], qmax[v][i]});
                u = parent[u][i];
                v = parent[v][i];
            }    
        }
        //같지 않은 상태까지 for문을 돌렸으므로, 마지막에 lca로 도달해줘야 한다.
        rmin = min({rmin, qmin[u][0], qmin[v][0]});
        rmax = max({rmax, qmax[u][0], qmax[v][0]});
    }
    return {rmin, rmax};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //-1로 초기화 안하면, 무조건 틀린다. 왜냐면
    //root를 넘어가도 root와 dept가 같아서 동일한 dept로 이동하지 못하고 넘어선다.
    memset(d, -1, sizeof(d));
    
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    d[1] = 0;
    dfs(1);
    
    for(int j = 1; j < lg; j++) {
        for(int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
            qmin[i][j] = min(qmin[i][j-1], qmin[parent[i][j-1]][j-1]);
            qmax[i][j] = max(qmax[i][j-1], qmax[parent[i][j-1]][j-1]);
        }
    }
    
    cin >> K;
    for(int i = 0; i < K; i++) {
        int d, e;
        cin >> d >> e;
        
        auto ret = lca(d, e);
        cout << ret.first << " " << ret.second << endl;
    }
}
