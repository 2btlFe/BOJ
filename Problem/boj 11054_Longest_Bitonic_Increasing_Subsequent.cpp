//boj 11054
//알고리즘: dp
//시간복잡도: O(N^2)
//DP 진행
//LIS - DP를 양쪽으로 2번 하면 된다. 


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int> arr;
	int x;
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		arr.push_back(x);
	}

	int d1[1001];
	int d2[1001];
	
	for(int k = 0; k < N; k++)
	{
		d1[k] = 1;
		for(int j = 0; j < k; j++)
		{
			if(arr[j] < arr[k]) d1[k] = max(d1[k], d1[j] + 1);
		}
	}
	
	reverse(arr.begin(), arr.end());
	
	for(int k = 0; k < N; k++)
	{
		d2[k] = 1;
		for(int j = 0; j < k; j++)
		{
			if(arr[j] < arr[k]) d2[k] = max(d2[k], d2[j] + 1);
		}
	}
	
	int big = 0;
	for(int i = 0; i < N; i++)
	{
		//printf("%d : %d %d\n", i, d1[i], d2[N-1-i]);
		
		big = max(big, d1[i] + d2[N-1-i] - 1); //N이라고 해서 틀렸었다 
	}
	
	cout << big;
	
}