/*
boj 14565 Find Inverse
Algorithm: extended_euclid
TC: O(logN)
SC: O(1)
Explaination:

확장 유클리드 호제법

ax + by = c
c % gcd(a, b) == 0 이면
배주 항등식을 풀 수 있다 

s(0) = 1, s(1) = 0
t(0) = 0, t(1) = 1
r(0) = a, r(1) = b

r(i) = r(i-2) % r(i-1)
q(i) = r(i-2) / r(i-1)
s(i) = s(i-2) - s(i-1) * q(i)
t(i) = t(i-2) - t(i-1) * q(i)

x = s + a*k
y = t - b*k

이를 이용해 곱셈역을 알 수 있다
a*c + n*k = 1

a*c = 1(mod n) 이면

a*c = nk + 1이고
k는 임의의 수이므로
a*c + n*k = 1로 두어 배주 항등식 푼다
양수 c를 찾아주면 된다

*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
    if(a % b == 0) return b;
    else return gcd(b, a%b);
}

tuple<ll, ll,ll> exEuclid(ll a, ll b, ll c) {
    
    ll g = gcd(a, b);
    if(c % g != 0) return make_tuple(-1, 1, 0);
    
    ll r0 = a, r1 = b;
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;
    
    while(r1) {
        ll r = r0 % r1;
        ll q = r0 / r1;
        ll s = s0 - q*s1;
        ll t = t0 - q*t1;
        
        r0 = r1; r1 = r;
        s0 = s1; s1 = s;
        t0 = t1; t1 = t;
    }
    
    ll sret = s0, tret = t0;
    while(sret <= 0) { 
        sret += b;
        tret -= a;
    }
    
    return make_tuple(g, sret, tret);
}

int main() {
    ll A, N; cin >> N >> A;
    ll reversePlus = N - (A % N);
    tuple<ll, ll, ll> reverseMul = exEuclid(A, N, 1);
    
    cout << reversePlus << " ";
    if(get<0>(reverseMul) == -1) cout << -1 << endl; 
    else {
        cout << get<1>(reverseMul) << endl;
    }
}
