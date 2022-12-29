/*
boj 2749 fibonacci 3
Algorithm: Divide Conquer
TC: O(logN)
SC: O(logN)
Explaination:

F2 F1
F1 F0 을 여러번 행렬 거듭제곱하면 풀 수 있다

typedef Matrix vector<vector<int> >
로도 풀 수 있다

operator를 만드는 것이 핵심이다 
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

const ll mod = 1e6;

struct Matrix {
    int n;
    vector<vector<ll> > mat;
  
    Matrix(int n) : n(n) {
        mat.resize(n, vector<ll>(n, 0));  
    }
      
    Matrix operator * (const Matrix& r) const {
        Matrix ret(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    ret.mat[i][j] = (ret.mat[i][j] + (mat[i][k] * r.mat[k][j]) % mod) % mod;
                }
            }
        }
        return ret;
    }
};

Matrix exponential(const Matrix& M, ll power) {
    if(power == 0) {
        Matrix ret(M.n);
        for(int i = 0; i < M.n; i++) ret.mat[i][i] = 1;
        return ret;
    }
    
    Matrix half = exponential(M, power/2);
    Matrix ret = half * half;
    if(power % 2 == 1) ret = ret * M;
    return ret;
}

void solve() {
    ll n; cin >> n;
    
    /*
    F2 F1
    F1 F0
    */
    Matrix fibo(2);
    fibo.mat[0][0] = fibo.mat[0][1] = fibo.mat[1][0] = 1;
    
    Matrix ret = exponential(fibo, n);
    cout << ret.mat[0][1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
