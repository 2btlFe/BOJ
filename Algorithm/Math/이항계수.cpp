#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll M = 1000*1000*1000+7;

ll power(ll x, ll n) {
    //base case
    if(n == 0) return 1;
    
    //odd
    if(n%2 == 1) {
        return (x * power(x, n-1))%M;
    } 
    
    //even
    ll half = power(x, n/2);
    return (half * half)%M; 

}



int main() {
    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    
    ll N, K;
    cin >> N >> K;
    
    ll A = 1; 
    for(int i = N; i > (N - K); i--) A = (A * i)%M;
    
    ll B = 1;
    for(int i = K; i > 0; i--) B = (B * i)%M;
    
    //B^(-1) == B^(M - 2) (mod M)
    
    B = power(B, M - 2);
    
    cout << (A * B)%M;
}
