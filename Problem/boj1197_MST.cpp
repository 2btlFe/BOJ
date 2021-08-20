//boj 1197 최소 스패닝 트리
//알고리즘: 크루스칼 알고리즘
//시간복잡도: O(elog(e))

/*
	MST를 공부하는 과정이고, prim 알고리즘도 써봐야겠다
	priority_queue를 사용하는 방법도 있다 -> 그것돟 알아보긴 할거다
	python으로 풀면 굉장히 빠르게 풀린다 -> python도 하긴 해야겠다 
*/

#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
	int node[2];
	int distance;
	
	//Edge 객체를 받아주는 method
	Edge(int a, int b, int c)
	{
		this -> node[0] = a;
		this -> node[1] = b;
		this -> distance = c;
	}
	
	//연산자 오버로딩의 경우 const를 꼭 쓰자
	//비교 연산자 오버로딩
	//정렬을 할 때 필요해서 사용한다 
	bool operator <(const Edge &edge) 
	{
		return this -> distance < edge.distance;
	}
};

int getParent(int parent[], int a)
{
	if(parent[a] == a) return a;
	return parent[a] = getParent(parent, parent[a]);  //parent도 갱신해줘야 한다
}

//질문-> 왜 main으로 돌아갔을 때 parent가 그대로 유지될까?? 반영이 안되어야 하는 거 아닌가 -> parent 자체가 point다
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if(a > b)
	{
		parent[a] = b;
	}
	else
	{
		parent[b] = a;
	}
}

bool isCycle(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if(a == b) return 1;
	else return 0;
}


int main()
{
	int V, E;
	cin >> V >> E;
	
	vector<Edge> v;
	
	for(int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		
		v.push_back(Edge(A, B, C));
	}
	
	//1. parent 초기화하기
	int parent[V+1];
	for(int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	
	//2. edge들을 오름차순으로 정렬하기 
	sort(v.begin(), v.end());
	
	//3. 가장 작은 edge부터 사이클 여부 확인하고 MST집합에 포함시킨다
	int sum = 0;
	for(Edge &edge: v)
	{
		if(!isCycle(parent, edge.node[0], edge.node[1]))
		{
			sum += edge.distance;
			unionParent(parent, edge.node[0], edge.node[1]);
		}	
	}
	
	cout << sum;

}
