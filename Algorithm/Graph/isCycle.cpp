int visited[501];
int finished[501];

//cycle 검출 : 역방향 간선 존재 확인  
bool dfs(int here) {
    bool ret = false;
    
    visited[here] = 1;
    for(int there : v[here]) {
        if(!visited[there]) ret |= dfs(there);
        else if(!finished[there]) ret = true;
    }
    finished[here] = 1;
    
    return ret;
}
