/*
TC: O(logn)
SC: O(logn)
*/
const ll mod= 1e9;

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
