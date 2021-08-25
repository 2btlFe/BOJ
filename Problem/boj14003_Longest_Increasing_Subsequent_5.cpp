#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N; //N이 10^6이라서 LIS-BS만 가능 
	cin >> N;
	
	vector<int> v;
	int x;
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	
	vector<int> track;
	
	vector<int> LIS;
	for(int i = 0; i < N; i++)
	{
		if(LIS.empty() || LIS.back() < v[i])
		{
			LIS.push_back(v[i]);
			track.push_back(LIS.size()-1);
		}
		else
		{
			auto it = lower_bound(LIS.begin(), LIS.end(), v[i]);
			int idx = it - LIS.begin();
			track.push_back(idx);
			*it = v[i];
		}
	}
	
	cout << LIS.size() << '\n';
	
	vector<int> ans;
	int order = LIS.size() - 1;
	for(int i = N-1; i> -1; i--)
	{
		if(track[i] == order)
		{
			ans.push_back(v[i]);
			order--;
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	for(int i : ans)
	{
		cout << i << " ";
	}
	
	
}