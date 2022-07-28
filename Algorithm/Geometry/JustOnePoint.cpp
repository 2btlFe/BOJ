#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long, long long>

using namespace std;

struct vector2 {
  double x, y;
  explicit vector2(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  
  bool operator == (const vector2& rhs) const {
    return x == rhs.x && y == rhs.y;
  }
  //더 왼쪽 아래에 있는 포인터 백터 찾기
  bool operator < (const vector2& rhs) const {
    return x != rhs.x ? x < rhs.x : y < rhs.y;
  }
  //벡터 덧셈과 뺄셈
  vector2 operator + (const vector2& rhs) const {
    return vector2(x + rhs.x, y + rhs.y);
  }
  vector2 operator - (const vector2& rhs) const {
    return vector2(x - rhs.x, y - rhs.y);
  }
  //실수로 곱셈
  vector2 operator * (const double rhs) const {
    return vector2(x * rhs, y * rhs);
  }
  //내적 외적
  double dot(const vector2& rhs) const {
    return x*rhs.x + y*rhs.y;
  }
  double cross(const vector2& rhs) const {
    return x*rhs.y - rhs.x*y;
  }
};

int ccw(vector2 a, vector2 b, vector2 c) {
    double ret = (b-a).cross(c-b);
    if(ret == 0) return 0; 
    else if(ret < 0) return -1;
    else return 1;
}

int lineIntersects(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    //한 직선 위에 있음 || 한 점에서 만남 
    if(ab == 0 && cd == 0) {
         if(b < a) swap(a, b);
         if(d < c) swap(c, d);
         
         //적어도 만난다면
         if(!(d < a || b < c)) {
             double det = (b-a).cross(d-c);
             if(det == 0) {//평행하다면 
                if(b == c) {
                    p = b;
                    return 1;
                } else if(a == d) {
                    p = a;
                    return 1;
                } else {
                    return 2;
                }
             } else { //교차한다면, 
                p = a + (b - a) *((c-a).cross(d-c) / det); 
                return 1;  
             }
         }
    } 
    //선분이 교차한다면 또는 한 점이 중간에서 만난다면 
    else {
        if(ab <= 0 && cd <= 0) { //한 점 에서 만난다면,
            double det = (b-a).cross(d-c);
            p = a + (b - a) *((c-a).cross(d-c) / det);    
            return 1;
        }
    }
    return 0;
}

int main() {
    double x1, y1, x2, y2;
    
    cin >> x1 >> y1 >> x2 >> y2;
    vector2 l1a(x1, y1), l1b(x2, y2); 
    
    cin >>x1 >> y1 >> x2 >> y2;
    vector2 l2a(x1, y1), l2b(x2, y2);
    
    vector2 p;
    int ok = lineIntersects(l1a, l1b, l2a, l2b, p);
    if(ok > 0) {
        cout << 1 <<"\n";
        if(ok == 1) printf("%.12f %.12f", p.x, p.y);
    } else {
        cout << 0 << "\n";
    }
}
