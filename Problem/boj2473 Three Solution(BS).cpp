/*
boj2473 Three Solution
Algorithm: Binary Search, Sort
Time Complexity(N^2(logN))
Explaination:
두 수는 고정하고 나머지 한 수를 남은 범위에서 이진 탐색을 한다
다만, lower_bound는 목표 수보다 크거나 같은 값을 뽑으므로, 작거나 같은 값도 고려해서
idx를 선정한다

나머지는 최소를 갱신하면 된다
하지만, 이 방법은 시간 복잡도가 너무 커서 별로다

투 포인터 방법도 있다
*/
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;

int main() {    
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<ll> v(n);
    for(ll&x : v) cin >> x;
    sort(all(v));
    
    int a, b, c;
    ll ret = 9876543210;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ll cand = v[i] + v[j];
            int idx = lower_bound(v.begin()+(j+1), v.end(), -cand) - v.begin();
            if(idx == n) {
                if(idx - 1 != j) {
                    idx = idx - 1;
                }
                else continue;
            }
            else if(idx - 1 != j && (abs(v[idx] + cand) > abs(v[idx - 1] + cand))){
                idx = idx - 1;
            }
            
            if(abs(cand + v[idx]) < ret){
              ret = abs(cand + v[idx]);
              a = i;
              b = j;
              c = idx;
            } 
        }
    }
    cout << v[a] << " " <<  v[b] << " " << v[c]; 
}


