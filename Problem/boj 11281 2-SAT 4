/*
boj 11281 2-SAT 4
Algorithm: 2-SAT, SCC
Time_Complexity; O(NlogN) sort가 지배
Explain:

A와 notA의 index 설정 때문에 틀렸었다

사실 아직 if(ret[var/2] == -1) ret[var/2] = !(var%2);
가 이해가 안 된다 
*/
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

const int MAX = 10000;
vector<int> adj[MAX*2];

int oppo(int n) {
    return (n % 2) ? n - 1 : n + 1;
}

// 각 정점의 컴포넌트 번호. 컴포넌트 번호는 0 부터 시작하며, 
// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;

// 각 정점의 발견 순서와 scc() 종료 여부
vector<int> discovered, finished;

// 정점의 번호를 담는 스택
stack<int> st;

int sccCounter, vertexCounter;

// here 를 루트로 하는 서브트리에서 역방향 간선으로 닿을 수 있는 최소의 발견 순서를
// 반환한다.
int scc(int here) {
  int ret = discovered[here] = vertexCounter++;
  // 스택에 here 를 넣는다. here 의 후손들은 모두 스택에서 here 후에 들어간다.
  st.push(here);  
  for(int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i];
    // (here,there) 가 트리 간선
    if(discovered[there] == -1) 
      ret = min(ret, scc(there));
    // (here,there) 가 역방향이나 교차 간선
    else if(discovered[there] < discovered[here] && sccId[there] == -1) 
      ret = min(ret, discovered[there]);
  }  
  // here 가 강결합 컴포넌트의 루트인가 확인한다
  if(ret == discovered[here]) {
    // here 를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다
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

// tarjan 의 SCC 알고리즘
vector<int> tarjanSCC() {
  // 배열들을 전부 초기화
  sccId = discovered = vector<int>(MAX*2, -1);
  finished = vector<int>(MAX*2, 0);
  // 카운터 초기화
  sccCounter = vertexCounter = 0;
  // 모든 정점에 대해 scc() 호출
  for(int i = 0; i < MAX*2; i++) if(discovered[i] == -1) scc(i);
  return sccId;
}

vector<int> solve2sat() {
    for(int i = 0; i < MAX*2; i+=2) {
        if(sccId[i] == sccId[i+1])
            return vector<int> ();
    }
    
    vector<int> ret(MAX*2, -1);
    
    //위상 정렬 순서로 확인한다 -> dfs로 SCC를 구했기 때문에 dfs의 역순으로 구하면 된다 DAG의 앞부분으로 간다 
    vector<pair<int, int> > sat_order;
    for(int i = 0; i < MAX*2; i++) {
        sat_order.push_back({-sccId[i], i});
    }
    sort(all(sat_order));
    
    
    for(int i = 0; i < MAX*2; i++){
        int var = sat_order[i].second;
        // 아직 해당 변수값이 설정되지 않았다면 지금 설정
        if(ret[var/2] == -1) ret[var/2] = !(var%2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A = (A<0 ? -(A+1)*2 : A*2-1);
        B = (B<0 ? -(B+1)*2 : B*2-1);
        
        adj[oppo(A)].push_back(B);
        adj[oppo(B)].push_back(A);
    }
    
    //scc별로 묶기
    tarjanSCC();
    
    vector<int> ans = solve2sat();
    if(ans.size() == 0) cout << 0;
    else {
        cout << 1 << endl;
        for(int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
    }
    
    
}
