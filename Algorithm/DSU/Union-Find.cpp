//부모 불러오기
int getParent(int parent[], int x) {
 if(parent[x] == x) return x;
 return parent[x] = getParent(parent, parent[x]);
}

//부모 합치기 -> 같은 부모 같게 하기
void unionParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  parent[max(a,b)] = min(a,b);
  return;
}

//같은 부모를 갖는지 확인
int findParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  return a == b;
}

//parent 갱신하기 
//iota(parent + 1, parent + 1 + n, 1);
