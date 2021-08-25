//boj 2565 전깃줄
//알고리즘 : LIS - DP
//시간복잡도 : O(N^2)
//사실상 쉽다 -> dp를 적용하는데에 있어서 A노드는 정렬용(순서 정하기)으로, B노드는 값용으로 넣어서 그냥 LIS하면 된다 

#include<bits/stdc++.h>

using namespace std;

class Elec{
public:
	int nodeA;
	int nodeB;
	
	Elec(int a, int b)
	{
		this->nodeA = a;
		this->nodeB = b;
	}
	
	bool operator<(Elec &elec)
	{
		return nodeA < elec.nodeA;
	}
	
};

/*
class 없이 이걸로 풀어도 됐다 

bool comp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

vector<pair<int, int> > v;

sort(v.being(), v.end(), comp);
*/

int main()
{
	int N;
	cin >> N;
	
	vector<Elec> v;
	
	int A, B;
	for(int i = 0; i < N; i++)
	{
		cin >> A >> B;
		v.push_back(Elec(A,B));
	}
	
	int dp[N+1];
	memset(dp, 0, sizeof(dp));
	
	sort(v.begin(), v.end());
	
	int big = 0;
	for(int k = 0; k < N; k++) //전깃줄의 개수
	{
		dp[k] = 1;
		for(int j = 0; j < k; j++)
		{
			if(v[k].nodeB > v[j].nodeB) //하나만 있어도 된다 
			{
				dp[k] = max(dp[k], dp[j] + 1);
			}
		}
		
		big = max(big, dp[k]);
	}
	
	cout << N - big;
}