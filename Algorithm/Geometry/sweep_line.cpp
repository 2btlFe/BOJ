/*
boj 2261 Closest Pair Point
Algorithm: sweep_line
TC: O(nlogn)
SC: O(nlogn) //set때문에 

1. x축을 기점으로 정렬
2. x좌표 차이가 d이내인 점들 모으기
3. y좌표 차이가 d이내인 점들 모아서 비교
4. d 갱신 
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

struct Point{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    
    bool operator <(const Point& p) const {
        if(y == p.y) {
            return x < p.x;
        } else {
            return y < p.y;
        }
    }
};

bool cmpX(const Point& A, const Point& B) {
    return A.x < B.x;
}

int dist(const Point& A, const Point& B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n; 
    vector<Point> v;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back(Point(a, b));
    }
    
    //1. x축을 기점으로 정렬
    sort(all(v), cmpX);
    
    int d = dist(v[0], v[1]);
    int start = 0;
    set<Point> cand = {v[0], v[1]};
    for(int i = 2; i < n; i++) {
        
        // 2. 기준 점과 x좌표 거리가 d이내인 점으로 조절
        //start를 통해 다음 반복시에도 사용
        for(int j = start; j < i; j++) {
            if((v[i].x - v[j].x) * (v[i].x - v[j].x) > d) {
                cand.erase(v[j]);
                start++;
            } else {
                break;
            }
        }
        
        // 3. 기준 점의 좌표와 거리가 d이내인 점으로 조절
        int yd = (int)sqrt(double(d)) + 1; //1 더 늘려서 한다 
        auto lowerpoint = Point(-10000, v[i].y-yd);
        auto upperpoint = Point(10000, v[i].y+yd);
        auto lower = cand.lower_bound(lowerpoint);
        auto upper = cand.upper_bound(upperpoint);
        
        for(auto it = lower; it != upper; it++) {
            d = min(d, dist(*it, v[i]));
        }
        cand.insert(v[i]);
    }
    
    cout << d << endl;
}
