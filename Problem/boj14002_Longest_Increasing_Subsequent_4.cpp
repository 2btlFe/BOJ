#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N; //N이 10^3이므로 dp도 가능
	cin >> N;
	
	int x;
	vector<int> v;
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	
	int dp[1001];
	int track[1001];
	int big = 0;
	for(int k = 0; k < N; k++)
	{
		dp[k] = 1;
		for(int i = 0; i < k; i++)
		{
			if(v[k] > v[i])
			{
				dp[k] = max(dp[k], dp[i] + 1);
			}
		}
		
		track[k] = dp[k];
		
		big = max(big, dp[k]);
	}
	
	cout << big << '\n';
	
	
	//역트래킹 시도 
	int order = big;
	vector<int> tracking;
	for(int i = N-1; i > -1; i--)
	{
		if(track[i] == order)
		{
			tracking.push_back(v[i]);
			order--;
		}
	}
	
	reverse(tracking.begin(), tracking.end());
	
	for(int i : tracking)
	{
		cout << i << " ";
	}
	
	
}