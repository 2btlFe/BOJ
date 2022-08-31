/*
boj 3648 Idol
Algorithm: SCC, 2-SAT
Time_Complexity: O(N)
Explaination:
일반적인 2-SAT문제로 보이지만,
1은 항상 true여야 한다는 조건이 붙었다.
이를 풀어내려면, 
1) 1부터 시작해서 dfs로 연결된 node들은 모두 1로 만들고
처음부터 끝까지 다시 dfs로 확인해서 
연결이 T -> F 가 나오는지 확인하면 된다.

2) X1은 무조건 참이어야 하므로
(X1 V X1)을 추가한다 
*/
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

const int MAX = 1000;
vector<int> adj[2*MAX];

//각 정점의 scc번호
vector<int> sccId;

// 각 정점의 발견 순서와 scc() 종료 여부
vector<int> discovered, finished;

// 정점의 번호를 담는 스택
stack<int> st;
int sccCounter, vertexCounter;

//here를 루트로 하는 서브트리에서 역방향 간선으로 닿을 수 있는 최소 발견 순서
int scc(int here) {
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    
    for(int there : adj[here]) {
        //1. 트리 간선 
        if(discovered[there] == -1) {
            ret = min(ret , scc(there));
        }
        
        //2. 역방향 or 교차 간선 
        else if(discovered[there] < discovered[here] && sccId[there] == -1) {
            ret = min(ret, discovered[there]);
        }
    }
    
    //이게 scc라면,
    if(ret == discovered[here]) {
        while(true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if(t == here) break;
        }
        ++sccCounter;
    }
    finished[here] = 1;
    return ret;
}

vector<int> tarjanSCC(int n) {
    //init
    sccId = discovered = vector<int>(n*2, -1);
    finished = vector<int>(n*2, 0);
    sccCounter = vertexCounter = 0;
    
    for(int i = 0; i < n*2; i++) {
        if(discovered[i] == -1) scc(i);
    }    
    
    return sccId;
}

int oppo(int n) {
    return (n % 2) ? n - 1 : n + 1;
}

void trueDFS(vector<int>& ret, int here) {
    for(int there: adj[here]) {
        if(ret[there] != -1) continue;
        
        ret[there] = 1;
        ret[oppo(there)] = 0;
        trueDFS(ret, there);
    }
}

int c[MAX*2];
bool check(const vector<int> &state, int here) {
    bool ret = true;
    for(int there : adj[here]) {
        if(state[here] == 1 && state[there] == 0) {
            ret &= false;
        }
        if(c[there] == 0) {
            c[there] = 1;
            ret &= check(state, there);
        }
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m; 
    while(cin >> n >> m) {
        
        for(int i = 0; i < 2*n; i++) adj[i].clear();
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            
            int na = (a < 0) ? (-2) * (a + 1) : 2*a - 1;
            int nb = (b < 0) ? (-2) * (b + 1) : 2*b - 1;
            
            adj[oppo(na)].push_back(nb);
            adj[oppo(nb)].push_back(na);
        }
        
        tarjanSCC(n);
        
        bool ok = true;
        for(int i = 0; i < n*2; i += 2) {
            if(sccId[i] == sccId[i+1]) {
                ok = false;
                break;
            }
            
        }
        
        vector<int> state(2*n, -1);
        state[0] = 0;
        state[1] = 1;
        trueDFS(state, 1);
        
        memset(c, 0, sizeof(c));
        for(int i = 0; i < 2*n; i++) {
            if(c[i] == 0) ok &= check(state, i);
        }
        
        if(ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
