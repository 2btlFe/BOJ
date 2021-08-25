//boj 2568 전깃줄-2
//알고리즘 : LIS-BS, LIS-역트래킹
//시간복잡도: O(n*logn)

#include<bits/stdc++.h>

using namespace std;

class Cord{
public:
	int nA;
	int nB;
	
	Cord(int a, int b)
	{
		this->nA = a;
		this->nB = b;
	}
	
	bool operator<(Cord &cord)
	{
		return nA < cord.nA;
	}
};

int main()
{
	int N;
	cin >> N;
	
	int a, b;
	vector<Cord> v;
	for(int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(Cord(a, b));
	}
	
	//오름차순 정렬
	sort(v.begin(), v.end());
	
	vector<int> LIS;
	int track[500001];
	
	for(int i = 0; i < N; i++)
	{
		if(LIS.empty() || LIS.back() < v[i].nB)
		{
			LIS.push_back(v[i].nB);
			track[i] = LIS.size() - 1;
		}
		else
		{
			auto it = lower_bound(LIS.begin(), LIS.end(), v[i].nB);
			int idx = it - LIS.begin();
			track[i] = idx;
			
			*it = v[i].nB;
		}
	}
	
	// 없애야 하는 전깃줄의 최소 개수
	cout << N - LIS.size() << '\n';
	
	//역트래킹
	int check[500001];
	int order = LIS.size() - 1;
	for(int i = N-1; i > -1; i--)
	{
		if(track[i] == order)
		{
			//cout << v[i].nA << '\n';
			order--;
			check[i] = 1;
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		if(check[i] != 1) cout << v[i].nA << '\n';
	}
	
	
	
}