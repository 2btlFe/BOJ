/*
boj 3653 Movie Collection
Algorithm: Segment_Tree, Fenwick_Tree
Time_Complexity: O(M * log(M + N))
Explaination:

inversion찾기는 기존의 것에 추가하는 느낌이라면,
이런 문제는 원래 정해진 것에 순서를 바꾸는 느낌이다.
고로, sun(999999) - sum(x) 같은 건 안 통한다

여기서는, m개의 여유공간을 앞에 만들어서 뽑힌 숫자는 1을 그 여유 공간에 둔다
그렇게 되면 sum(pos) - 1은 정확히 나보다 위에 있는 dvd의 갯수가 된다
pos를 저장하는 idx[] 도 필요하다 그래야 정확한 범위를 구할 수 있다 

교훈이 있는 세그먼트 문제다 
*/

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Fenwick {
  vector<int> tree;
  Fenwick(int n) : tree(n+1) {}
  
  int sum(int pos) {
      pos++;
      int ret = 0;
      while(pos > 0) {
        ret += tree[pos];    
        pos &= (pos - 1);
      }
      return ret;
  }
  
  void add(int pos, int val) {
      pos++;
      while(pos < tree.size()) {
          tree[pos] += val;
          pos += (pos & -pos);
      }
  }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        auto dvd = Fenwick(m + n);
        int idx[n];
        for(int i = m; i < m + n; i++) {
            dvd.add(i, 1);
            idx[i - m] = i;
        }
        
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            x--;
            int pos = idx[x];
            cout << dvd.sum(pos) - 1 << " ";
            
            dvd.add(pos, -1);
            dvd.add(m - 1 - i, 1);
            idx[x] = m - 1 - i;
        }
        cout << endl;
    }
}
