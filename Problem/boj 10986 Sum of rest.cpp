/*
boj 10986 Sum of rest.cpp
Algorithm: prefix_sum, hash
TC: O(n)
SC: O(n)
Explaination:

그냥 나머지 별로 누적합을 모아서
nC2 해준다
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
    int N, M; cin >> N >> M;
    
    map<int, int> m;
    m[0] = 1;
    ll sum = 0;
    for(int i = 1; i <= N; i++) {
        int x; cin >> x;
        sum = (sum + x) % M;
        m[sum]++;
    }
    
    ll cnt = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        ll tmp = (*it).second;
        cnt += tmp * (tmp -1) / 2;
    }
    
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
