//알고리즘: meet in the middle + dfs + binary search
//시간 복잡도: O(N*2^(N/2))

/*
meet in the middle은 굉장히 강력한 방법이다.
조심해야 하는 사항이 있는데
-> 둘 다 비어있는 경우 1가지를 빼준다

vector에 일단 그냥 넣고 upper_bound랑 lower_bound를 써서
정확히 그 갯수를 구한다
이게 매핑보다 더 좋을 수 있다
->왜냐면 매핑해야 할 숫자가 약 10^10이면 arr[99999]++
는 비효율적이다. 
다만, vector에 넣고 binary_search를 쓰는 경우는
binary_search를 2번해야 한다는 점에서 비효율적이다

시간복잡도와 공간복잡도 중에서 골라야 한다
*/



#include<bits/stdc++.h>

using namespace std;

vector<int> v;
vector<long long> cnt1;
vector<long long> cnt2;
int N, S;
long long ans;

void dfs1(int idx, long long sum)
{
	if(idx == N/2) return;
	long long tmp = sum+v[idx];
	//dfs1에서만 답이 나올 수도 있다
	if(tmp == S) ans++;
	cnt1.push_back(tmp);
	
	dfs1(idx+1, sum);
	dfs1(idx+1, tmp);
	
	return;
}

void dfs2(int idx, long long sum)
{
	if(idx == N) return;
	long long tmp = sum+v[idx];
	//dfs2에서만 답이 나올 수도 있다
	if(tmp == S) ans++;
	cnt2.push_back(tmp);
	
	dfs2(idx+1, sum);
	dfs2(idx+1, tmp);
	
	return;
}

int main()
{
	cin >> N >> S;
	
	int tmp;
	for(int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	
	ans = 0;
	
	dfs1(0, 0);
	dfs2(N/2, 0);
	
	sort(cnt1.begin(), cnt1.end());
	sort(cnt2.begin(), cnt2.end());
	
	for(long long i : cnt1)
	{
		//정확하게 그 갯수를 구하고 싶으면 이렇게 한다 
		int u = upper_bound(cnt2.begin(), cnt2.end(), S - i) - cnt2.begin();
		int l = lower_bound(cnt2.begin(), cnt2.end(), S - i) - cnt2.begin();
		
		//cout << i << " " << S-i << " " << u << " " << l << endl;
		
		ans += u - l;
	}
	
	cout << ans;
}