//boj 9372 상근이의 여행
//가중치가 없는 MST 만들기 -> 그냥 최소치는 N-1 이다
//넌센스 문제다 


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		
		for(int i = 0; i < M; i++)
		{
			int A, B;
			cin >> A >> B;
		}
		
		cout << N-1 << '\n';
	}
}