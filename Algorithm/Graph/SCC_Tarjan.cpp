//TC: O(V+E)

const int MAX = 1e5;
vector<int> adj[MAX + 1];

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
    // (here,there) 무시할 수 없는 교차 간선(SCC Id가 아직 정해지지 않았고 나보다 먼저 접근된 노드)
    else if(sccId[there] == -1) 
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
  return ret;
}

// tarjan 의 SCC 알고리즘
vector<int> tarjanSCC() {
  // 배열들을 전부 초기화
  sccId = discovered = vector<int>(MAX, -1);
  // 카운터 초기화
  sccCounter = vertexCounter = 0;
  // 모든 정점에 대해 scc() 호출
  for(int i = 0; i < MAX; i++) if(discovered[i] == -1) scc(i);
  return sccId;
}
