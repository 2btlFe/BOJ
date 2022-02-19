/*
boj2623 Music Program
Algorithm: Topology Sort
Time Complexity: O(n + n)
Explaination:

중복되어 들어가도 어차피 그만큼 --를 시켜주므로
중복 신경 쓰지 말고 그냥 하면 됐다

*/
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;

int main() {    
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> v[n+1];
    int num[n+1];
    memset(num, 0, sizeof(num));
    
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        int before, next; 
        cin >> before;
        for(int i = 1; i < x; i++) {
            cin >> next;
            v[before].push_back(next);
            num[next]++;
            before = next;
        }
    }
    
    vector<int> ans;
    queue<int> q;
    //초기값들 넣어주기
    for(int i = 1; i <= n; i++) {
        if(num[i] == 0) q.push(i);
    }
    
    //topology sort
    while(!q.empty()) {
        int x = q.front();
        ans.push_back(x);
        q.pop();
        
        for(int y : v[x]) {
            if(--num[y] == 0) q.push(y);
        }
    }
    
    if(ans.size() != n) {
        cout << 0 << endl;
    }else {
        for(int i : ans) cout << i << endl;
    }
}







