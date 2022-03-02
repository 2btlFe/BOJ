
int visited[100001];
int finished[100001];
bool cycle = false;

//cycle 검출 : 역방향 간선 존재 확인  
void dfs(int here) {
    visited[here] = 1;
    for(int there : e[here]) {
        if(!visited[there]) dfs(there);
        else if(!finished[there]) cycle = true;
    }
    finished[here] = 1;
}
