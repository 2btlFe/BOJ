/*
boj 25330 SHOW ME THE DUNGEON
Algorithm: Backtracking, Combination
TC: O(2^n)
SC: O(2^n)
Explaination:
backtracking은 거의 2^26까지 가능하다 
만약 주어진 N이 작다면, Combination 혹은 Permutation을 
고민해보자
Combination을 하는 방법은

한다, 안 한다로 하는 방법이 있고
combination(idx+1, sum)
combination(idx+1, sum+v[i])

아니면, for문을 줘서 할 수도 있다
for(int i = idx; i < S.size(); i++) {
  combination(i + 1, sum+v[i]);
}

조건이 있을 경우 for문을 쓰는 것이 좋다 
*/

#include <bits/stdc++.h>

using namespace std;

int ret = 0;
void combination(const vector<pair<int, int> > &v, const int& idx, const int& sumA, const int& rest, const int& sumP) {
    if(idx == v.size()) {
        return;
    }
    
    for(int i = idx; i < v.size(); i++) {
        int Ai = v[i].first;
        int Pi = v[i].second;
        
        if(rest < sumA + Ai) break;
        ret = max(ret, sumP + Pi);
        combination(v, i+1, sumA + Ai, rest - (sumA + Ai), sumP + Pi);
    }
    return;
}

int main() {
    int N, K; cin >> N >> K;
    vector<pair<int, int> > v;
    
    vector<int> tmp(N);
    for(int &x : tmp) cin >> x;
    
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        v.push_back({tmp[i], x});
    }
    
    sort(v.begin(), v.end());
    
    combination(v, 0, 0, K, 0);
    
    cout << ret << endl;
}

