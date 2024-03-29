/*
알고리즘: 다익스트라
목적: 가중치가 양수인 그래프에서 특정 노드로부터 각 노드까지의 최소거리를 구하기 위함이다
시간복잡도: O(NlogN)
원리: 우선 순위 큐

const int INF = 987654321;
vector<pair<int, int> > a[7]; //간선 정보
int d[7]; //최소 비용

void dijkstra(int start) {
  d[start] = 0;
  priority_queue<pair<int, int> > pq;  //우선 순위 큐는 큰 값부터 뽑는다 고로 최솟값을 찾고 싶으면 음수로 바꿔서 넣자
  pq.push({start, 0});
  
  while(!pq.empty()) {
    int current = pq.top().first;
    int distance = -pq.top().second;
    pq.pop();
    
    if(d[current] <= distance) continue;
    for(auto& i : a[current]) {
      int next = i.first;
      int nextDistance = distance + i.second;
      
      if(nextDistance < d[next]) {
        d[next] = nextDistance;
        pq.push({next, -nextDistance});
      }
    }
  }
}








*/
