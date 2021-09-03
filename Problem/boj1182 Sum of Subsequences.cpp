//부분 수열 만들기 -> combination
/*
1. c++ next_permutation 이용하기
2. python from itertools import combinations
3. meet in the middle 

*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, S;
	int ans = 0;
	cin >> N >> S;
	
	vector<int> v;
	int tmp;
	for(int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	
	//편의를 위해 
	sort(v.begin(), v.end());
	
	for(int k = 1; k <= v.size(); k++)
	{
		vector<int> ind;
		//k개는 포함
		for(int i = 0; i < k; i++)
		{
			ind.push_back(1);
		}
		
		//N-k개는 포함x
		for(int i = 0; i < N-k; i++)
		{
			ind.push_back(0);
		}
		
		sort(ind.begin(), ind.end());
		
		do{
			int sum = 0;
			
			for(int i = 0; i < N; i++)
			{
				if(ind[i] == 1)
				{
					//cout << v[i] << " ";
					sum += v[i];
				}
			}
			
			//printf("\n");
			if(sum == S) ans++;
			
		}while(next_permutation(ind.begin(), ind.end()));
	}
	
	cout << ans;

}