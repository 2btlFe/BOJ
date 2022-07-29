/*LCA by Sparse Table
Algorithm: LCA, Sparse_Table
Time_Complexity: O(NlogN)  탐색은 O(logN)
Explain: 
2^k의 parent만 찾아도 전체의 parent 경우를 찾을 수 있다
*/

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M;
const int MAX_N = 100001;
const int lg = 20;
vector<int> adj[MAX_N];
int d[MAX_N];
int parent[MAX_N][lg];

//dfs로 모든 노드의 dept를 갱신한다 root는 0, 존재하지 않는 노드는 -1
void dfs(int here) {
    for(int there : adj[here]) {
        if(d[there] != -1) continue;
        d[there] = d[here] + 1;
        parent[there][0] = here;
        dfs(there);
    }
}

//parent를 전부 갱신한다 parent[i][0] 부터 down_top으로
void parentCal() {
    for(int j = 1; j < lg; j++) {
        for(int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }    
}

int lca(int u, int v) {
    //1. 더 깊은 노드(u)를 같은 높이 까지 올려준다
    if(d[u] < d[v]) swap(u, v);
    for(int i = lg - 1; i >= 0; i--) {
        if(d[parent[u][i]] >= d[v]) {
            u = parent[u][i];
        }
    }
    
    //2. 만약 u와 v가 다르다면, 동시에 올려준다. 단, lca 직전까지 말이다.
    if(u != v) {
        for(int i = lg - 1; i >= 0; i--) {
            if(parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        //3. lca직전까지 올려줬으므로, 한 칸 더 올린다.
        u = parent[u][0];
        //v = parnet[v][0];
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //존재하지 않는 노드의 dept는 -1로 만들어준다
    memset(d, -1, sizeof(d));
    
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    d[1] = 0;
    dfs(1);
    parentCal();    
    
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}
