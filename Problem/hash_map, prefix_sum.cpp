/*
boj 25332 sum of number8
Algorithm: hash_map, prefix_sum
TC: O(n*logn)
SC: O(n)
Explaination:

hash-map과 prefix_sum의 콜라보
psumA[i] - psumB[i] = psumA[tmp] - psumB[tmp]
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
    int N; cin >> N;
    vector<ll> psumA(N+1), psumB(N+1);
    for(int i = 1; i <= N; i++) {
        ll x; cin >> x;
        psumA[i] = psumA[i-1] + x; 
    }
    for(int i = 1; i <= N; i++) {
        ll x; cin >> x;
        psumB[i] = psumB[i-1] + x; 
    }
    
    map<ll, int> difCnt;
    difCnt[0] = 1;
    ll ret = 0;
    for(int i = 1; i <= N; i++) {
        ll dif = psumA[i] - psumB[i];
        ret += difCnt[dif];
        difCnt[dif]++;
    }
    cout << ret << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
