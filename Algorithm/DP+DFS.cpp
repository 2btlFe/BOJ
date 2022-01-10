//dfs는 당연히 깊은 곳부터 계산을 하기 때문에
//누적 합을 쓸 필요가 없다
//또한, 상태를 신경 쓸 필요가 없다
//dp+dfs는 그냥 안쪽부터 신경쓰면 된다 

#include<bits/stdc++.h>

using namespace std;

int cache[502][502];
int orient[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int cost[502][502];
int M, N;


int dfs(int x, int y)
{
  int &ret = cache[x][y];
  if(ret != -1) return ret;

  //base case
  if(x == M && y == N) return ret = 1;

  ret = 0;
  for(int i = 0; i < 4; i++)
  {
    int nx = x + orient[i][0];
    int ny = y + orient[i][1];

    if(nx <= 0 || nx > M || ny <= 0 || ny > N) continue;

    if(cost[nx][ny] < cost[x][y])
    {
      ret += dfs(nx, ny);
    }  
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  memset(cache, -1, sizeof(cache));
  
  cin >> M >> N;

  for(int i = 1; i <= M; i++)
  {
    for(int j = 1; j <= N; j++)
    {
      int x;
      cin >> x;
      cost[i][j] = x;
    }
  }
  cout << dfs(1, 1);
  
}
