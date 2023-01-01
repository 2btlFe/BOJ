/*
boj 14425 string set
Algorithm: Hash_Map
TC: O(m*log(n)*|s|)
SC: O(|s|n)
Explaination:

map을 이용하면 검색에 O(logn)이 쓰이기 대문에
map의 크기자체가 크지 않다면
문자열 집합에 특정 문자열이 존재하는지 확인하는 쿼리는
트라이 대신 해쉬맵을 사용해도 좋다
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
    int N, M; cin >> N >> M;
    map<string, bool> m;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        m[s]= true;
    }
    
    int ret = 0;
    while(M--) {
        string s; cin >> s;
        if(m[s]) ret++; 
    }
    
    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
