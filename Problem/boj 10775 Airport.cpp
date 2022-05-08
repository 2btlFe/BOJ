/*
boj 10775 Airport
TimeComplexity: O(n * a(n)) = O(n)
Explaination:

Greedy + Only getParent()
*/

int parent[100001];

int getParent(int x) {
    if(x == parent[x]) return x;
    
    return parent[x] = getParent(parent[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int G, P; cin >> G >> P;
    int ret = 0;
    
    for(int i = 0; i <= G; i++) parent[i] = i;
    
    while(P--) {
        int x; cin >> x;
        int gate = getParent(x);
        
        if(gate == 0) break;
        
        ret++;
        parent[gate]--;
    }
    
    cout << ret;
    
}
