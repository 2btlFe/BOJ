/*
boj 1562 Number of Stair
알고리즘: DP + Bit Mask
시간복잡도(O(N*2^11*10)*O(10)))

boj 2098 TCP랑 똑같다
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll cache[101][10][2500];
const int M = 1e9;
int N;

ll stair(int n, int before, int memory) {
  //base case
  if(n == 0) return memory == (1<<10) - 1 ? 1 : 0;

  ll &ret = cache[n][before][memory];
  if(ret != -1) return ret;

  ret = 0;
  if(before == 0) {
    ret = (ret + stair(n - 1, 1, memory|(1<<1))%M)%M;
  }
  else if(before == 9) {
    ret = (ret + stair(n - 1, 8, memory|(1<<8))%M)%M;
  }
  else if(before == -1) {
    for(int i = 1; i <= 9; i++) {
      ret = (ret + stair(n - 1, i, memory|(1<<i))%M)%M;
    }
  }
  else {
    ret = (ret + stair(n - 1, before - 1, memory|(1<<(before-1)))%M)%M;
    ret = (ret + stair(n - 1, before + 1, memory|(1<<(before+1)))%M)%M;
  }

  return ret;
}

int main()
{
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  memset(cache, -1, sizeof(cache));
 
  cin >> N;

  cout << stair(N, -1, 0);
  return 0;
}
