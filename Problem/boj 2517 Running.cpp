/*
boj 2517 Running
Algorithm: Fenwick, Cooridinate_compression
Time Complexity: O(NlogN)
Explain:

N <= 10^6 이면, 그냥 Fenwick만 써도 된다
하지만,
N > 10^6 && N <= 10^9 이면, Fenwick과 좌표압축을 같이 써야한다. 
그냥 중복을 없애고 각 값을 정렬한 뒤의 좌표를 사용한다고 생각하면 된다
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 500000;
int arr[INF+1], fenwick[INF+1];
vector<int> v;
int S;

int getIdx(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int sum(int pos) {
    int ret = 0;
    while(pos > 0) {
        ret += fenwick[pos];
        pos &= (pos - 1);
    }
    return ret;
}

void add(int pos, int val) {
    while(pos <= S) {
        fenwick[pos] += val;
        pos += (pos & -pos);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] = x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    S = unique(v.begin(), v.end()) - v.begin();
    
    int ret = 0;
    for(int i = 0; i < n; i++) {
        int idx = getIdx(arr[i]);
        add(idx, 1);
        int kth = sum(S) - sum(idx) + 1;
        cout << kth << "\n";
    }
}
