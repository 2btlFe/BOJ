/*
boj 7578 Factory
Algorithm: Segment_Tree, Fenwick_Tree
Time_Complexity: O(Nlog1eg)
Explain:

사실 봤었던 유형이다.
인덱스로 tree를 만드는 것이 아니라
값으로 tree를 만들어 누적합으로 지금까지 나보다 
큰 값의 개수를 찾는 것이다

이런 문제는 '역전'을 유의깊게 생각해야 한다
인덱스는 나보다 작은데 값은 나보다 큰 수의 개수를 찾는 문제
*/
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

struct Fenwick {
  vector<int> tree;
  
  Fenwick(int n) : tree(n+1) {}
  
  ll sum(int pos) {
      pos++;
      ll ret = 0;
      while(pos > 0) {
          ret += tree[pos];
          pos &= (pos - 1);
      }
      return ret;
  }
  
  void add(int pos, int val) {
      pos++;
      while(pos <= tree.size()) {
          tree[pos] += val;
          pos += (pos & -pos);
      }
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    
    map<int, int> A;
    map<int, int> B;
    
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        A[i] = x;
    }
    
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        B[x] = i;
    }
    
    Fenwick cable(1000000);
    ll ret = 0;
    for(int i = 0; i < N; i++) {
        int num = B[A[i]];
        ret += cable.sum(999999) - cable.sum(num);
        cable.add(num, 1);
    }
    
    cout << ret << endl;
}
