/*
boj 3015 oasis reunion
Algorithm: stack
Time_Complexity:  O(N)
Explain:

내 풀이: 왼쪽 -> 오른쪽, 오른쪽 -> 왼쪽으로 두 번 스캔을 하면서
현재 stack의 top보다 크면 개수 세기
작거나 같으면 무시한다
단, stack을 풀어야할 때는 같은 수는 겹쳐지게 하면서 내려온다 

최적화 풀이는 
그냥 한 번만 왔다갔다 한다

내 풀이와의 차이점은 나는 앞에 숫자를 기준으로 삼았고
최적화 풀이는 뒤의 숫자를 기준으로 삼았다




*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int INF = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    ll num[2][n];
    
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        num[0][i] = x;
        num[1][n-1-i] = x;
    }
    
    ll ret = 0;
    for(int iter = 0; iter < 2; iter++) {
        stack<pair<ll, ll>> s;
        for(int i = 0; i < n; i++) {
            ll target = num[iter][i];
            while(!s.empty() && s.top().first < target) {
                auto candidate= s.top();
                s.pop();
                
                ll plus = (s.empty()) ? 0 : s.top().second * candidate.second;
                    
                if(!s.empty() && s.top().first == candidate.first) {
                    ll tmp = candidate.second + s.top().second;
                    s.pop();
                    s.push({candidate.first, tmp});
                    if(iter == 0) ret += plus;
                } else {
                    ret += plus;
                }
            }
            s.push({target, 1});
        }
        while(!s.empty()) {
            auto candidate= s.top();
            s.pop();
            ll plus = (s.empty()) ? 0 : s.top().second * candidate.second;
                
            if(!s.empty() && s.top().first == candidate.first) {
                ll tmp = candidate.second + s.top().second;
                s.pop();                
                s.push({candidate.first, tmp});
                if(iter == 0) ret += plus;
            } else {
                ret += plus;
            }
        }  
    }
    
    cout << ret << endl;
}
