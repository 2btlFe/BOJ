/*
boj 12971 Number Game
Algorithm: CRT
TC: O(nlogn)
SC: O(n)
Explaination:

x = m1k1 + a1 = m2k2 + a2
m1k1 + m2k2 = a2 - a1
확장 유클리드 호제법으로 m1k1 + m2k2 = a2 - a1
의 g, k1, k2 구하기

k1에 (a2-a1)/g 곱해주기
x = m1k1 + a1에 대입
x = m1k1 + a1 + l*(m1*m2/g)
양수 x가 조건을 만족하는 최소 x이다 
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;


//as + bt = g 에 대반 s, t 를 구해줌 
tuple<ll, ll, ll> extended_euclidean(ll a, ll b) {
    if (b == 0)
        return make_tuple(a, 1, 0);
    auto [g, x, y] = extended_euclidean(b, a%b);
    return make_tuple(g, y, x-(a/b)*y);
}

int main() {
    int sz = 3;
    vector<ll> m(sz), a(sz);
    for(ll &x : m) cin >> x;
    for(ll &x : a) cin >> x;
    
    //ret = m1k1 + a1 = m2k2 + a2
    //m1k1 + m2k2 = (a2 - a1) 구하기
    ll m1 = m[0], a1 = a[0];
    ll ret;
    for(int i = 1; i < sz; i++) {
        ll m2 = m[i], a2 = a[i];
        //확장 유클리드 호제법으로 m1k1 + m2k2 = g구하기 
        auto [g, k1, _] = extended_euclidean(m1, m2);
        if((a2 - a1) % g != 0) {
            ret = -1;
            break;
        } else {
            //(a2 - a1) / g 곱해줘서 진정한 k1 찾아주기 
            k1 *= (a2 - a1) / g;
            ret = (m1 * k1 + a1) % (m1 * m2 / g);
            while(ret <= 0) {
                ret += m1 * m2 / g;
            }
            m1 = m1 * m2 / g;
            a1 = ret;
        }
    }
    
    if(ret == -1 || ret >= 1e9) cout << -1 << endl;
    else cout << ret << endl;
}
