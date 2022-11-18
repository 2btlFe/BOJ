/*
Algorithm: Trie
TC: 한 문자열 당 O(|S|)
SC: 포인터 크기 * 포인터 배열 개수 * 총노드의 개수 
1000자리 문자열이 1000개 -> 100만 노드 필요
포인터 크기가 8byte면 
약 200MB 필요

*/

#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(),x.end()
#define endl "\n"

using namespace std;

const int ALPHABETS = 26;
int toNumber(char ch) {return ch - 'a';}

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
    
    void insert(const char* key) {
        //문자열이 끝나면 terminal를 참으로 바꾸고 종료 
        if(*key == 0) {
            terminal = true;
        } else {
            int next = toNumber(*key);
            if(children[next] == NULL) 
                children[next] = new TrieNode();
            //해당 자식 노드로 재귀 호출 
            children[next] -> insert(key + 1);
        }
    }
    
    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        int next = toNumber(*key);
        if(children[next] == NULL) return NULL;
        return children[next] -> find(key + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M; 
    cin >> N >> M;
    
    TrieNode* Root = new TrieNode();
    
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        Root->insert(s.c_str());
    }
    
    int ret = 0;
    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if(Root->find(s.c_str())) ret++;
    }
    
    cout << ret << endl;
}
