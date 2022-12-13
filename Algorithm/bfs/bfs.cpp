void BFS(int s) {
  queue<int> q;
  d[s] = 0;
  q.push(s);
  
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    
    for(auto i : v[x]) {
      int nx = i;
      d[nx] = d[x] + 1;
      q.push(nx);
    }
  }
  return;
}
