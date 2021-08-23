//boj1774 우주신과의 교감
//알고리즘 : 크루스칼

#include<bits/stdc++.h>

using namespace std;

int parent[1001];

class Edge{
public:
	int node[2];
	double dist;
	
	Edge(int a, int b, double c)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->dist = c;
	}
	
	bool operator <(Edge &edge)
	{
		return dist < edge.dist;
	}
};

int getParent(int x)
{
	if(parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]); //여기서 return 계속 실수한다 
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	
	if(a > b) parent[a] = b;
	else parent[b] = a;
}

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector<pair<int,int> > p;
	int x, y;
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		p.push_back({x,y});
	}
	
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	
	
	int a, b;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		unionParent(a, b);
	}
	
	vector<Edge> v;
	for(int i = 0; i < N; i++)
	{
		for(int j = i+1; j < N; j++)
		{
			double distance = sqrt( pow( p[i].first - p[j].first , 2.0) + pow( p[i].second - p[j].second ,2.0) );
			v.push_back(Edge(i+1, j+1, distance));
		}
	}
	

	sort(v.begin(), v.end());
	
	double sum = 0.0;
	for(Edge & edge : v)
	{
		if(getParent(edge.node[0]) != getParent(edge.node[1]))
		{
			sum += edge.dist;
			unionParent(edge.node[0], edge.node[1]);
		}
	}
	
	printf("%.2f",sum); //소수점 둘째자리까지 구하라 
}