#include<bits/stdc++.h>

using namespace std;

int main()
{
	int INF = 1e9;

	int TC;
	cin >> TC;
	
	while(TC--)
	{	
		
		//준비 단계
		vector<pair<int, pair<int, int> > > edge;
		int N, M, W;
		cin >> N >> M >> W;
		
		int d[N+2]; //약간 걱정됨
		fill(d, d+N+1, INF); //초기화
		
		int S, E, T;
		for(int i = 0; i < M; i++)
		{
			cin >> S >> E >> T;
			
			edge.push_back({S,{E, T}});
			edge.push_back({E,{S, T}});
		}
		
		for(int i = 0; i < W; i++)
		{
			cin >> S >> E >> T;
			
			edge.push_back({S,{E, -T}});
		}
		//입력 완료
		
		d[1] = 0;
		
		int check = 0;
		
		//V 만큼 반복, 단, V번째에서 cycle이 발생하는지 확인 
		for(int i = 1; i <= N-1; i++) //N-1번 반복 시행 
		{
			for(int j = 0; j < edge.size(); j++) //1부터 N까지의 edge 실행 
			{
				int From = edge[j].first;
				int to = edge[j].second.first;
				int val = edge[j].second.second;
				
				if(d[to] > d[From] + val)
				{
					d[to] = d[From] + val;
					//printf("check %d %d %d -> %d\n",From, to, val, d[to]);
				}
			}
		}
		
		//대망의 N번째 -> 음의 사이클 확인 
		for(int j = 0; j < edge.size(); j++) //1부터 N까지의 edge 실행 
		{
			int From = edge[j].first;
			int to = edge[j].second.first;
			int val = edge[j].second.second;
			
			if(d[to] > d[From] + val)
			{
				check = 1;
				break;
			}
		}
		
		//결론 
		if(check == 1)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';			
		}
	}
}
