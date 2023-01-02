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

//gcd(a, b) = ax+ by
tuple<ll, ll, ll> extended_gcd(ll a, ll b)
{
    if (a == 0) {
        return make_tuple(b, 0, 1);
    }
 
    ll gcd, x, y;
 
    // 함수에 의해 반환된 튜플을 변수로 압축을 풉니다.
    tie(gcd, x, y) = extended_gcd(b % a, a);
 
    return make_tuple(gcd, (y - (b/a) * x), x);
}


/* 곱셈의 역원 구하기 
int main() {
    ll A, N; cin >> N >> A;
    ll reversePlus = N - (A % N);
    tuple<ll, ll, ll> reverseMul = extended_gcd(A, N);
    
    cout << reversePlus << " ";
    if(1%get<0>(reverseMul)) cout << -1 << endl; 
    else {
        cout << (get<1>(reverseMul) + N) % N << endl;
    }
}
*/
