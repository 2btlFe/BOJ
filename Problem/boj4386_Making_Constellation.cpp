//boj 4386 별자리 만들기
//알고리즘 : 크루스칼 알고리즘
//edge를 미리 구하고 크루스칼에 임하는 것이 키포인트이다.
//좌표평면에서 MST를 만드는 문제이다 

#include<bits/stdc++.h>

using namespace std;

int parent[101];

class Edge{
public:
	int node[2];
	double dist;
	
	Edge(int a, int b, double c){
		this->node[0] = a;
		this->node[1] = b;
		this->dist = c;
	}
	
	bool operator <(Edge &edge)
	{
		return dist < edge.dist;
	}
};

int getParent(int a)
{
	if(parent[a] == a) return a;
	else return parent[a] = getParent(parent[a]);
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
	int n;
	cin >> n;
	
	// 1. node들 받기
	vector<pair<double, double>> pos; 
	double x, y;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		pos.push_back({x,y});
	}
	
	//2. edge 길이 구하기
	vector<Edge> v;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			double distance = sqrt(pow(pos[i].first - pos[j].first, 2.0) + pow(pos[i].second - pos[j].second, 2.0));
			
			v.push_back(Edge(i+1, j+1, distance));
		}
	}
	
	//3. 크루스칼 알고리즘 시작
	for(int i = 1; i < n; i++)
	{
		parent[i] = i;
	}
	
	sort(v.begin(), v.end());
	
	double sum = 0;
	
	for(Edge &edge : v)
	{
		if(getParent(edge.node[0]) != getParent(edge.node[1]))
		{
			unionParent(edge.node[0], edge.node[1]);
			sum += edge.dist;	
		}
	}
	
	cout << sum;

}