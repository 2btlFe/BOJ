/*
boj 25577 열 정렬정렬 정
Algorithm: permutation_cycle_decomposition
TC: O(nlogn)
SC: O(n)
Explaination:
순열 사이클 분할을 이용해
원소들을 나눌 수 소집단으로 묶을 수 있고
소집단에서는 사이클이 나타나기 때문에
2개씩 잡고 swap을 하게 될 경우 
n - 1번 swap을 통해 n개를 정렬할 수 있다
*/

#include <bits/stdc++.h>
#define endl "\n"
#define all(x) x.begin(), x.end()
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.emplace_back(x, i);
    }
    sort(all(v));
    
    //순열 사이클 만들기 
    vector<int> f(n);
    for(int i = 0; i < n; i++) {
        f[i] = v[i].second;
    }
    
    vector<bool> chk(n, false);
    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(!chk[i]) {
            int cnt = 0;
            for(auto u = i; !chk[u]; u = f[u]) {
                chk[u] = true;
                cnt++;
            }
            ret += cnt - 1;
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
