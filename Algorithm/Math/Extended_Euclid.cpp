/*
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


//as + bt = gcd(a,b) 에 대한 s, t 를 구해줌 
tuple<ll, ll, ll> extended_euclidean(ll a, ll b) {
    if (b == 0)
        return make_tuple(a, 1, 0);
    auto [g, x, y] = extended_euclidean(b, a%b);
    return make_tuple(g, y, x-(a/b)*y);
}

ll modInverse(ll a, ll m) {
    auto [g, s, _] = extended_euclidean(a, m);
    if(g != 1) return -1;
    return (s % m + m) % m;
}
