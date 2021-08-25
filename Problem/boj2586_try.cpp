/*
N이 10^5이므로 LIS-BS를 적용해야 하고
정확한 조합을 원하므로 -> arr를 하나 더 적용해서 풀어야 한다 
tracking 연습이 필요하다 
*/


#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first;
}

int main()
{
	int N;
	cin >> N;
	
	vector<pair<int, int> > v;
	int finish[500001];
	
	int A, B;
	for(int i = 0; i < N; i++)
	{
		cin >> A >> B;
		v.push_back({A,B});
		finish[B] = 0;
	}
	
	sort(v.begin(), v.end(), cmp);
	
	vector<int> LIS;
	vector<int> comb;
	
	//초기값 넣기
	LIS.push_back(v[0].second);
	comb.push_back(v[0].second);
	
	for(int i = 1; i < N; i++)
	{
		int tmp = v[i].second;
		
		if(tmp > LIS.back())
		{
			LIS.push_back(tmp);
		}
		else
		{
			auto it = lower_bound(LIS.begin(), LIS.end(), tmp);
			*it = tmp;	
		}
		
		//바꾸기 
		if(comb.back() > tmp && LIS.size() > comb.size())
		{
			comb = LIS;
		}
		
		
		auto it_c = lower_bound(comb.begin(), comb.end(), tmp);
		

		if(tmp > comb.back())
		{
			comb.push_back(tmp);
		}
		else if(it_c  == --comb.end())
		{
			*it_c  = tmp;
		}
		
	}
	
	cout << N - LIS.size() << '\n';
	
	for(int i : comb)
	{
		finish[i] = 1;
	}
	
	for(auto tmp : v)
	{
		if(finish[tmp.second] == 0) cout << tmp.first << '\n';
	}
	
}