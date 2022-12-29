/*
boj 1451 Divide into Ractangle
Algorithm: prefix_sum
TC: O(n^2)
SC: O(n^2)
Explaination:
indexing 이 어려웠다
조건분기도 어렵다

얻은 교훈은 
2차원 prefix의 경우
ll presum(const vector<vector<int> >& pre, int a, int b, int c, int d) {
    return pre[a][b] - pre[c][b] - pre[a][d] + pre[c][d];
}
만들어 사용하면 실수하지 않을 것 같다
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

ll presum(const vector<vector<int> >& pre, int a, int b, int c, int d) {
    return pre[a][b] - pre[c][b] - pre[a][d] + pre[c][d];
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int> > v(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) {
            v[i][j+1] = s[j] - '0';
        }
    }
    
    //prefix_sum
    vector<vector<int> > pre(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + v[i][j];
        }
    }
    
    ll ret = 0;
    //1
    for(int i = 1; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            ll s1 = presum(pre, n, i, 0, 0);
            ll s2 = presum(pre, n, j, 0, i);
            ll s3 = presum(pre, n, m, 0, j);
            ret = max(ret, s1*s2*s3);
        }
    }
    
    //2
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ll s1 = presum(pre, i, m, 0, 0);
            ll s2 = presum(pre, j, m, i, 0);
            ll s3 = presum(pre, n, m, j, 0);
            ret = max(ret, s1*s2*s3);
        }
    }
    
    //3
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            ll s1 = presum(pre, i, j, 0, 0);
            ll s2 = presum(pre, n, j, i, 0);
            ll s3 = presum(pre, n, m, 0, j);
            ret = max(ret, s1*s2*s3);
            
            s2 = presum(pre, i, m, 0, j);
            s3 = presum(pre, n, m, i, 0);
            ret = max(ret, s1*s2*s3);
        }
    }
    
    //4
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            ll s1 = presum(pre, n, m, i, j);
            ll s2 = presum(pre, i, m, 0, j);
            ll s3 = presum(pre, n, j, 0, 0);
            ret = max(ret, s1*s2*s3);
        
            s2 = presum(pre, i, m, 0, 0);
            s3 = presum(pre, n, j, i, 0);
            ret = max(ret, s1*s2*s3);
        }
    }
    
    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
