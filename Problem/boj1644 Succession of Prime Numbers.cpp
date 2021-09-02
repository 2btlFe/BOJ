//알고리즘: 에라토스테네스의 체 + 시작점이 같은 투포인터
//시간 복잡도 : O(NloglogN)

//풀이 방법은 많다 
//1. 반복문 queue를 사용하여 작은 수부터 버리기
//2. 투 포인터 사용
//3. 합의 배열을 더 만들고 이진 탐색으로 가능한 케이스 찾기 


#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int isPrime[4000001];
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
	
	vector<int> prime;
	for(int i = 2; i <= N; i++)
	{
		if(isPrime[i])
		{
			//cout << i << '\n';
			prime.push_back(i);
		} 
	}
	
	//투 포인터 시작
	// l < cost <= r
	int l = -1;
	int r = -1;
	int size = prime.size();
	
	int cost = 0;
	int ans = 0;
	while(r < size)
	{
		if(cost < N)
		{
			r++;  //overflow 가능
			if(r >= size) break;
			cost += prime[r];
		}
		else if(cost == N)
		{
			ans++;
			r++; l++;
			if(r >= size) break;
			cost += prime[r];
			cost -= prime[l];
		}
		else if(cost > N)
		{
			l++;
			cost -= prime[l];
		}
	}
	
	cout << ans;

}