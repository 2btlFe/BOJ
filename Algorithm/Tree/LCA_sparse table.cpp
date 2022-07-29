/*
LCA를 찾는 시간복잡도: O(logN)

1) dfs를 이용해 deptth 부여
2) query의 양 끝 중 depth가 더 작은 요소를 dept의 차이가 없을 때까지 2^k번째 조상까지 올림
3) depth가 같으므로 parent가 같을 때까지 서로 올림
4) LCA 찾음
*/


#include <bits/stdc++.h>

using namespace std;
const int lg = 16;

vector<int> v[100001];
int depth[100001];
int ac[100001][lg+1];

void dfs(int here, int parent) {
    
    //현재 상태 
    ac[here][0] = parent;
    depth[here] = depth[parent] + 1;
    
    //dp
    for(int i = 1; i <= lg; i++) {
        //here의 2^i번째 ac는 
        //here의 2^i-1번째 ac의 2^i-1번째 ac이다.
        int tmp = ac[here][i-1];
        ac[here][i] = ac[tmp][i-1];
    }
    
    //dfs 진행 
    for(int there : v[here]) {
        if(there == parent) continue;
        dfs(there, here);
    }
}

int lca(int a, int b) {
    //a를 더 깊은 노드로 설정 
    if(depth[a] < depth[b]) swap(a, b);
    
    for(int i = lg; i >= 0; i--) {
        if(depth[ac[a][i]] >= depth[b]){
            a = ac[a][i];
        }
    }
    
    if(a != b) {
        for(int i = lg; i >= 0; i--) {
            if(ac[a][i] != ac[b][i]) {
                a = ac[a][i];
                b = ac[b][i];
            }
        }
        return ac[a][0];
    } else {
        return a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N-1; i++) {
        int here, there;
        cin >> here >> there;
        v[here].push_back(there);
        v[there].push_back(here);
    }
    
    //0은 없는 node
    dfs(1, 0);
    
    int M; cin >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
