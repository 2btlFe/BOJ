//boj 1647 도시 분할 계획
//알고리즘 : 크루스칼 알고리즘
//시간 복잡도: e*log(e)

//되게 직관적인 문제였다 
//마을을 모두 잇는 문제는 크루스칼 알고리즘을 쓰면 된다 

#include<bits/stdc++.h>

using namespace std;

class Edge
{
public:
	int node[2];
	int dist;
	
	Edge(int a, int b, int c)
	{
		this -> node[0] = a;
		this -> node[1] = b;
		this -> dist = c;
	}
	
	bool operator <(Edge &edge)
	{
		return dist < edge.dist; //true인 조건
	}
};

//Union-Find 알고리즘
int getParent(int parent[], int x)
{
	if(parent[x] == x) return x;
	else return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

int isCycle(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if(a == b) return 1;
	else return 0;
}

int main()
{
	int N, M;
	cin >> N >> M;
	
	int A, B, C;
	vector<Edge> v;
	for(int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		v.push_back(Edge(A, B, C) ); //하나만 있어도 됨
	}
	
	//1. parent 초기화
	int parent[N+1];
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	
	//2. 오름차순 정렬
	sort(v.begin(), v.end());
	
	//3. 사이클이 생기지 않는 조건 하에 모으기
	int sum = 0; //MST cost
	int big = 0; //가장 유지비가 많이 드는 edge 하나
	
	for(Edge &edge : v)
	{
		if(!isCycle(parent, edge.node[0], edge.node[1]))
		{
			unionParent(parent, edge.node[0], edge.node[1]);
			sum += edge.dist;
			big = max(big, edge.dist);
		}
	}
	
	// 4. 가장 유지비가 많이 드는 edge 하나를 제거하여 2개의 MST 생성
	cout <<	sum - big;

}