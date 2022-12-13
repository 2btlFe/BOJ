//이 알고리즘은 정확한 값은 못 구하고 갯수만 구할 수 있다

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int> lis;
	
	int x;		
	cin >> x;
	lis.push_back(x);
	
	for(int i = 1; i < N; i++)
	{
		cin >> x;
		
		if(x > lis.back())
		{
			lis.push_back(x);
		}
		else
		{
			auto it = lower_bound(lis.begin(), lis.end(), x);
			*it = x;
		}
	}
	
	cout << lis.size();
}
