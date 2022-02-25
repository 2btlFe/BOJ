void dfs(auto c[], auto x) {
  if(c[x]) return;
  c[x] = true;
  for(auto i : a[x]) dfs(i);
  return;
}

int orient[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N;
void dfs2(auto board[][], auto r, auto c) {
  if(board[r][c]) return;
  board[r][c] = true;
  for(int i = 0; i < 4; i++) {
    int nr = r + orient[i][0];
    int nc = c + orient[i][1];
    
    if(nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc]) continue;
    dfs(nr, nc);
  }
  return;
}
