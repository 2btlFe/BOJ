/*
boj 2261 Closest Pair Point
Algorithm: Divide & Conquer
TC: O(nlogn^2)
SC: O(nlogn)

1) x좌표 기준으로 정렬
2) 가운데 번호로 영역 나누기
3) k = min(k1, k2)
4) 합치기 기준선을 기점으로 -k, +k 인 점들을 모아서
y값 기준으로 정렬
5) 밑에서부터 y값 거리 k인 점들까지만 비교 
6) 최소 값 리턴
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

struct Point{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

bool cmpX(const Point& A, const Point& B) {
    return A.x < B.x;
}

bool cmpY(const Point& A, const Point& B) {
    return A.y < B.y;
}

int distance(const Point& A, const Point& B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int closest_pair(const vector<Point>& v, int idx, int n) {
    if(n == 2) {
        return distance(v[idx], v[idx+1]);
    } else if(n == 3) {
        return min({distance(v[idx], v[idx + 1]), distance(v[idx+1], v[idx + 2]), distance(v[idx], v[idx + 2])});
    }
    
    int line = (v[idx + n/2 - 1].x + v[idx + n/2].x) / 2;
    int d = min(closest_pair(v, idx, n/2), closest_pair(v, idx + n/2, n - n/2));
    
    //기준선과의 x좌표 거리가 d 이내인 점만 선별한다
    vector<Point> mid;
    for(int i = idx; i < idx + n; i++) {
        int tmp = abs(line - v[i].x);
        if(tmp * tmp < d) mid.push_back(v[i]);
    }
    
    //y좌표로 정렬
    sort(all(mid), cmpY);
    
    for(int i = 0; i < mid.size(); i++) {
        //이게 최대 7개 밖에 확인을 안 한다 -> 증명이 있는데 이해는 좀 못 했다 
        for(int j = i + 1; j < mid.size(); j++) {
            //만약 y축 상의 거리가 d 이상이면 넘어간다 
            if((mid[j].y - mid[i].y) * (mid[j].y - mid[i].y) >= d) break;
            d = min(d, distance(mid[i], mid[j]));
        }
    }
    
    return d;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n; 
    vector<Point> v;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back(Point(a, b));
    }
    sort(all(v), cmpX);
    
    cout << closest_pair(v, 0, n);
}
