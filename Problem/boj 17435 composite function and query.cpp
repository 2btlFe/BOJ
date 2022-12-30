/*
boj 17435 composite function and query
Algorithm: sparse_table
TC: O(mlogn)
SC: O(nlogn)
Explaination:

희소 배열의 특징은 
7 = 4 + 2 + 1 처럼
2의 k제곱수들의 정보로 큰 수를 분석하는 것이다

고로 n만큼 걸려야 하는 장업이 logn만큼만 걸린다
다만, nlogn의 선작업을 해야 한다

sp[k][i] = sp[k-1][sp[k-1][i]]

#팁
만약 log2n을 구하고 싶다면
int log2n = log2(n) 그냥 해주다
n도 double로 캐스트 되고
log2(n)도 int로 캐스트 된다
*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
    int m; cin >> m;
    vector<int> f(m+1);
    for(int i = 1; i <= m; i++) {
        cin >> f[i];
    }
    
    int N = 5*1e5;
    int logN = log2(N);
    vector<vector<int> > sp(logN + 1, vector<int>(m+1));
    
    for(int i = 1; i <= m; i++) {
        sp[0][i] = f[i];
    }
    
    for(int k = 1; k < logN + 1; k++) {
        for(int i = 1; i <= m; i++) {
            int next = sp[k-1][i];
            sp[k][i] = sp[k-1][next];
        }
    }
    
    int Q; cin >> Q;
    while(Q--) {
        int n, x; cin >> n >> x;
        for(int bit = log2(n); bit >= 0; bit--) {
            if((n & (1<<bit)) != 0) {
                x = sp[bit][x];
            }
        }
        cout << x << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
}
