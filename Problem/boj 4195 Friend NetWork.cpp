/*
boj 4195 Friend NetWork
Algorithm: DSU, HashMap
TC: O(F*|S|*log(F))
SC: O(|S|*F)
Explaination:

괜히 #define endl "\n" 하는 것이 아니다
시간을 정말 많이 줄여준다
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

map<string, int> m;
const int N = 1e5+1;

int getParent(int parent[], int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b, vector<int>& numFriend) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a <= b) {
        parent[b] = a;
        numFriend[a] += numFriend[b];
    } else {
        parent[a] = b;
        numFriend[b] += numFriend[a];
    }
    return;
}

void solve() {
    int F; cin >> F;
    int idx = 0;
    
    int parent[2*N];
    for(int i = 0; i < 2*N; i++) {
        parent[i] = i;
    }
    
    vector<int> numFriend(2*N, 1);
    
    while(F--) {
        string s1, s2;
        cin >> s1 >> s2;
    
        if(m.count(s1) == 0) m[s1] = idx++;
        if(m.count(s2) == 0) m[s2] = idx++;
        
        int ps1 = getParent(parent, m[s1]);
        int ps2 = getParent(parent, m[s2]);
        if(ps1 == ps2) {
            cout << numFriend[min(ps1, ps2)] << endl;
        } else {
            cout << numFriend[ps1] + numFriend[ps2] << endl;
            unionParent(parent, m[s1], m[s2], numFriend);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt; cin >> tt;
    while(tt--) {
        m.clear();
        solve();
    }
    
}
