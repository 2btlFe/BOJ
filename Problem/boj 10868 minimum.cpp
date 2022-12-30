/*
boj 10868 minimum
Algorithm: sparse_table
TC: O(mlogn)
SC: O(nlogn)
Explaination:

희소 배열의 특징은 
7 = 4 + 2 + 1 처럼
2의 k제곱수들의 정보로 큰 수를 분석하는 것이다

고로 n만큼 걸려야 하는 장업이 logn만큼만 걸린다
다만, nlogn의 선작업을 해야 한다

sp[k][i] = min(sp[k-1][i], sp[k-1][i + pow(2, k-1)])


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
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    
    int logn = log2(n); //2번 자동 캐스트
    vector<vector<int> > sp(logn+1, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        sp[0][i] = v[i];
    }
    
    for(int k = 1; k < logn+1; k++) {
        for(int i = 0; i < n; i++) {
            int last = i + pow(2, k) - 1;
            if(last >= n) break;
            
            int next = i + pow(2, k-1);
            sp[k][i] = min(sp[k-1][i], sp[k-1][next]);
        }
    }
    
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        int ret = 1e9 + 9;
        int num = b - a + 1;
        
        for(int bit = log2(num); bit >= 0; bit--) {
            if((num & (1<<bit)) != 0) {
                ret = min(ret, sp[bit][a]);
                a += pow(2, bit);
            }
        }
        cout << ret << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
}
