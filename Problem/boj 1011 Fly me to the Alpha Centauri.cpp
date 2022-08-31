/*
boj 1011 Fly me to the Alpha Centauri
Algorithm: Math, Binary_Search
Time_Complexity:

2^31개의 dp를 만들 수는 없었다
그래서 2*10^5까지의 n*(n+1)값을 기준으로
그 값보다 작은 개수까지 포함해주고 1번을 더할지 2번을 더할지 경계를
생각하면 되는 문제였다
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<ll> v;
    for(ll i = 0; i <= 200001; i++) {
        v.push_back(i * (i + 1));
    }
    
    int t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        ll diff = b - a;
        
        if(diff == 1) {
            cout << 1 << endl;
            continue;
        }
        
        auto it = upper_bound(all(v), diff) - 1;
        ll num = *it;
        ll n = it - v.begin();
        ll ret = 2 * n;
        
        if(diff - num != 0) {
            if(n >= diff - num  - 1) ret += 1;
            else ret += 2;
        }
        
        cout << ret << endl;
    }
}
