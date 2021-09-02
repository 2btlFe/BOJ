#include<bits/stdc++.h>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	
	int isPrime[1000001];
	memset(isPrime, 1, sizeof(isPrime));
	//이거 해줘야지 맞는다 -> 0,1에서 쓰레기 값이 들어갈 수 있으므로 초기화 해주자 
	isPrime[0] = 0;
	isPrime[1] = 0;
	
	int sqrtn = int(sqrt(N));
	for(int i = 2; i <= sqrtn; i++)
	{
		if(isPrime[i] == 0) continue;
		for(int j = i*i; j <= N; j += i)
		{
			isPrime[j] = 0;
		}
	}
	
	for(int i = M; i <= N; i++)
	{
		if(isPrime[i]) cout << i << '\n';
	}
	
	
	
	
}