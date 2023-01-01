/*
boj 5588 find zodiac sign
Algorithm: Set
TC: O(n*m*log(m))
SC: O(n)
Explaination:

map을 사용하면 메모리 초과가 발생할 수 있다
이럴 경우, set을 사용해주어야 한다 
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<pair<int, int> > zodiac;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        zodiac.push_back({x, y});
    }
    
    set<pair<int, int>> starPos;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        starPos.insert({x,y});
    }
    
    int retX, retY;
    for(auto it = starPos.begin(); it != starPos.end(); it++) {

        int difX = (*it).first - zodiac[0].first;
        int difY = (*it).second - zodiac[0].second;
        
        bool ok = true;
        for(int i = 0; i < m; i++) {
            ok &= (starPos.find({zodiac[i].first + difX, zodiac[i].second + difY}) != starPos.end());
        }
        if(ok) {
            retX = difX;
            retY = difY;
            break;
        }
    }
    cout << retX << " " << retY << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
