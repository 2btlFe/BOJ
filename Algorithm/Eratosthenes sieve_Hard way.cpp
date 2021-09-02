//에라토스테네스의 체 - 최적화 방법
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	//1) 2차원 배열 생성
	int arr[n+1];
	fill(arr+2, arr+n+1, 1);
	
	//sqrt(n) 까지만 해도 괜찮다
	int sqn = int(sqrt(n));
	
	for(int i = 2; i <= sqn; i++)
	{
		//3) 이미 지워진 숫자는 건너 뛴다
		if(arr[i] == 0) continue;
		//2) 2부터 시작해서 특정 숫자의 배수에 해당하는 숫자들을 지운다
		//*i^2부터 봐도 된다 -> 어차피 i^2이하의 숫자는 for문으로 확인하게 된다 
		for(int j = i*i; j <= n; j += i)
		{
			arr[j] = 0;
		}
	}
	
	//4) 남은 숫자들을 출력
	for(int i = 2; i <= n; i++)
	{
		if(arr[i] != 0) cout << i << " ";
	}
	
}