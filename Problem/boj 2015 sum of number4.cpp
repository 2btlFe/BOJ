/*
boj 2015 sum of number4
Algorithm: hash_map, prefix_sum
TC: O(n*logn)
SC: O(n)
Explaination:

hash-map과 prefix_sum의 콜라보

*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    map<ll, int> m;
    m[0] = 1;
    ll sum = 0, ret = 0;
    while(N--) {
        ll x; cin >> x;
        sum += x;
        ret += m[sum - K];
        m[sum]++;
    }
    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
