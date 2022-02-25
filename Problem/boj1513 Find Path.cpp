/*
boj1513 Find Path
Algorithm: DP + DFS
Time Complexity: O(N^4) * O(2);
Explaination:
 예외 사항을 정하는 것이 어려웠다
 
 늘 base case에 유의해서 풀자
 안 되면 표를 작성해도 좋다
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define len(x) (int) (x).size()
#define all(x) x.begin(), (x).end()
#define endl "\n"

int orient[2][2] = {{0, -1}, {-1, 0}};
int isArcade[51][51];
ll cache[51][51][51][53];
int N, M, C;
const int MOD = 1000007;


//Definition: y,x까지 arcade개의 오락실이 남음
ll findPath(int y, int x, int arcade, int order) {
    //base case
    if(y == 1 && x == 1) {
        if(isArcade[y][x] > 0) return (arcade == 1 && isArcade[y][x] < order);
        else return (arcade == 0);
    }
    
    //memoization
    ll& ret = cache[y][x][arcade][order];
    if(ret != -1) return ret;
    
    //recursion
    ret = 0;
    for(int i = 0; i < 2; i++) {
        int py = y + orient[i][0];
        int px = x + orient[i][1];
        
        if(py > N || py <= 0 || px > M || px <= 0) continue;
        
        int porder = isArcade[y][x];
        
        if(porder == 0) ret = (ret + findPath(py,px,arcade, order))%MOD;  
        else if(porder < order) ret = (ret + findPath(py, px, arcade - 1,porder))%MOD;
    }
    return ret;
}

int main()
{
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  memset(cache, -1, sizeof(cache));
  
  cin >> N >> M >> C;
  
  int cnt = 1;
  for(int i = 0; i < C; i++) {
    int y, x;
    cin >> y >> x;
    isArcade[y][x] = cnt++;
  }
  
  for(int i = 0; i <= C; i++) {
      cout << findPath(N, M, i, 52) << " ";
  }
}
