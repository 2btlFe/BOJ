#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int x, arr[1001];
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		arr[i] = x;
	}
	
	
	int big = 0;
	int dp[1001];
	for(int k = 0; k < N; k++)
	{
		dp[k] = 1;
		for(int j = 0; j < k; j++)
		{
			if(arr[j] < arr[k]) dp[k] = max(dp[k], dp[j] + 1);
		}
		
		big = max(big, dp[k]); //갱신이 필요 
	}
	
	cout << big;
}