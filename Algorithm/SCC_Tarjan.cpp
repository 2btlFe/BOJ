vector<vector<int> > SCC;
vector<int> v[10001];
int discovered[10001];
bool finished[10001];
int order = 1;
stack<int> s;

int tarjan(int here) {
    discovered[here] = order++;
    s.push(here);
    
    //역방향 간선인지 교차 간선인지 확인
    int parent = discovered[here];
    for(int there : v[here]) {
        if(!discovered[there]) parent = min(parent, tarjan(there));
        else if(!finished[there]) parent = min(parent, discovered[there]);
    }
    
    if(parent == discovered[here]) {
        vector<int> scc;
        while(1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == here) break;
        }
        sort(all(scc));
        SCC.push_back(scc);
    }
    return parent;
}
