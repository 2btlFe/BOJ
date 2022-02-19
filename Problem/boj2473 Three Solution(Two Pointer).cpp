/*
boj2473 Three Solution(Two Pointer)
Algorithm: Two Pointer, Sort
Time Complexity(N^2)
Explaination:
두 수는 고정하고 나머지 한 수를 남은 범위에서 이진 탐색을 한다
다만, lower_bound는 목표 수보다 크거나 같은 값을 뽑으므로, 작거나 같은 값도 고려해서
idx를 선정한다
나머지는 최소를 갱신하면 된다
하지만, 이 방법은 시간 복잡도가 너무 커서 별로다

투 포인터 방법도 있다
하나의 수를 고정하고 나머지 두 수로 투 포인터를 돌린다
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
    
    int s, m, e;
    ll ret = 9876543210;
    ll a, b, c;
    for(int s = 0; s < n - 2; s++) {
        m = s + 1;
        e = n - 1;
        while(m < e) {
            ll sum = v[s] + v[m] + v[e];
            if(abs(sum) < ret) {
                ret = abs(sum);
                a = s;
                b = m;
                c = e;
            }
            
            if(sum < 0) m++;
            else if(sum > 0) e--;
            else {
                cout << v[a] << " " <<  v[b] << " " << v[c];
                return 0;
            }
        }
    }
    
    cout << v[a] << " " <<  v[b] << " " << v[c];
}







