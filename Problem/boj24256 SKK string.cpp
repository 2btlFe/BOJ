/*
boj 24256 SKK string
Algorithm: DP, Prefix_Sum
Time Complexity: O(len(s)*3);
Explianation:

핵심은 아래와 같다
부분합을 통해 문자열 안에 s와 k가 있는지 확인한다
count가 같은 최대 - 최소를 비고해 dp로 ret를 구한다

if(nums[big] - nums[small] > 0 && numk[big] - numk[small] > 0)
    ret = max(ret, dp[i][0] - dp[i][1]);
*/

#include<bits/stdc++.h>
using namespace std;
#define len(x) (int) (x).size()
#define all(x) x.begin(), (x).end()
#define endl "\n"
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define fi first
#define se second

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
      
    const int range = 300000;
    string s;
    cin >> s;
      
    int count = 0;
    int dp[range+1][2];
    int numk[100001], nums[100001];
    
    for(int i = 0; i <= range; i++) {
        dp[i][0] = 0;
        dp[i][1] = range+2;
    };
    dp[100000][0] = 0; dp[100000][1] = 0;
    
    for(int i = 0; i < len(s); i++) {
        nums[i+1] = nums[i];
        numk[i+1] = numk[i];
        if(s[i] == 'S') {nums[i+1]++; count += 2;}
        else if(s[i] == 'K') {numk[i+1]++; count -= 1;}
        
        dp[count + 100000][0] = max(dp[count + 100000][0], i+1);
        dp[count + 100000][1] = min(dp[count + 100000][1], i+1);
    }
  
    int ret = -1;
    for(int i = 0; i <= range; i++) {
        int big = (dp[i][0] > 0) ? dp[i][0] - 1 : 0;
        int small = (dp[i][1] > 0) ? dp[i][1] - 1 : 0;
        
        if(nums[big] - nums[small] > 0 && numk[big] - numk[small] > 0)
            ret = max(ret, dp[i][0] - dp[i][1]);
    }
    cout << ret;
}
