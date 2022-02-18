const double PI = 2.0*acos(0.0);

struct vector2{
  double x, y;
  explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_){}
  //벡터의 비교
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
  //벡터의 길이를 반환
  double norm() const { return hypot(x, y); }
  //방향이 같은 단위 벡터를 반환
  //영백테에 대해서 반환하면 반환값은 정의되지 않는다
  vector2 normalize() const{
    return vector2(x/norm(), y/norm());
  }
  double polar() const {return fmod(atan2(y,x) + 2*PI, 2*PI);}
  //내적 외적
  double dot(const vector2& rhs) const {
    return x*rhs.x + y*rhs.y;
  }
  double cross(const vector2& rhs) const {
    return x*rhs.y - rhs.x*y;
  }
  //벡터를 rhs벡터에 사영한 결과
  vector2 project(const vector2& rhs) const {
    vector2 r = rhs.normalize();
    return r*r.dot(*this);
  }
};

//두 벡터의 방향 판별
double ccw(vector2 a, vector2 b) {
  return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b){
  return ccw(a-p, b-p);
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
  double ab = ccw(a, b, c) * ccw(a, b, d);
  double cd = ccw(c, d, a) * ccw(c, d, b);

  //한 직선에 있을 때
  if(ab == 0 && cd == 0) {
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);

    return !(b < c || d < a); 
    
  }
  return ab <= 0 && cd <= 0;
}
