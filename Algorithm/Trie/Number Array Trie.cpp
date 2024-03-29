/*
숫자 Trie
그냥 재귀적으로 접근하면 된다
*/
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()

using namespace std;

int N, M; 
const int ALPHABETS = 12;
int toNumber(char ch) {return ch - '0';}

int ret = 0;
struct TrieNode {
    TrieNode* children[ALPHABETS];
    bool terminal;
    TrieNode() : terminal(false) {
        //0으로 초기화 
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for(int i = 0; i < ALPHABETS; i++) {
            if(children[i]) 
                delete children[i];
        }
    }
    
    void insert(const vector<int>& v, int idx) {
        //문자열이 끝나면 terminal를 참으로 바꾸고 종료 
        if(idx == M) {
            terminal = true;
        } else {
            int next = v[idx];
            if(children[next] == NULL) 
                children[next] = new TrieNode();
            //해당 자식 노드로 재귀 호출 
            children[next] -> insert(v, idx + 1);
        }
    }
    
    int find(const vector<int>& v, int idx) {
        if(idx == M) {
            return idx;
        }
        int next = v[idx];
        if(children[next] == NULL) {
            return idx;
        }
        return children[next] -> find(v, idx + 1);
    }
};
void solve() {
    
    cin >> N >> M;
    TrieNode* Root = new TrieNode();
    
    vector<vector<int> > v;
    for(int i = 0; i < N; i++) {
        vector<int> tmp;
        for(int j = 0; j < M; j++) {
            int x; cin >> x;
            tmp.push_back(x-1);
        }
        v.push_back(tmp);
    }
    
    for(int i = 0; i < N; i++) {
        vector<int> tmp(M);
        for(int j = 0; j < M; j++) {
            tmp[v[i][j]] = j;
        }
        Root->insert(tmp, 0);
    }
    
    for(int i = 0; i < N; i++) {
        cout << Root->find(v[i], 0) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
