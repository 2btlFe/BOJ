/*
boj 11444 fibonacci 6
Algorithm: matrix_square, Divide&Conquer
TC: O(logN)
SC: O(logN)
Explaination:
well-known 문제
행렬 거듭제곱 문제이다 
*/

#include <bits/stdc++.h>
#define ll long long
#define enld "\n"
#define all(x) x.begin(), x.end()

using namespace std;

const ll mod = 1e9+7;

struct Matrix{
    int n;
    vector<vector<ll>> mat;
    
    Matrix(int n) : n(n) { 
        mat.resize(n, vector<ll>(n, 0));
    }
      
    Matrix operator * (const Matrix& rhs) {
        Matrix ret(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % mod)%mod;    
                }
            }
        }
        return ret;
    }
};

Matrix exponential(const Matrix& m, ll power) {
    if(power == 0) {
        Matrix ret(m.n);
        for(int i = 0; i < m.n; i++) ret.mat[i][i] = 1;
        return ret;
    }
    
    Matrix half = exponential(m, power/2);
    Matrix ret = half * half;
    if(power % 2 == 1) ret = ret * m;
    return ret;
}

void solve() {
    Matrix m(2);
    m.mat[0][0] = m.mat[0][1] = m.mat[1][0] = 1;
    m.mat[1][1] = 0;
    
    ll N; cin >> N;
    Matrix ret = exponential(m, N);
    cout << ret.mat[0][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
}
