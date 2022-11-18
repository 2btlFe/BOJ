/*
boj 5052 Phone List
Algorithm: Sort, Trie
TC: |K|NlogN * T  -> 10 * (10000 * log(10000)) * 40
SC: 포인터 크기 * 포인터 배열 개수 * 노드 개수(문자열 길이 * 문자열 개수 ) 
노드 개수 = (10 * 10000) = 10^5개
포인터 크기 = 8byte
포인터 배열 개수 = 10개
8MB 정도 

Explaination:
1. 문자열 오름차순 정렬
2. find 결과 존재 하면 false
3. 존재하지 않으면 insert로 계속 진행
4. 접두사 단어가 없으면 true

특징은 alphabet이 아니라 digit을 사용한다는 것이다 
alphabet으로 하면 런타임 에러가 나온다 

*/

#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(),x.end()
#define endl "\n"

using namespace std;

const int ALPHABETS = 26;
const int DIGIT = 10;
int toNumber(char ch) {return ch - '0';}

struct TrieNode {
    TrieNode* children[10];
    bool terminal;
    TrieNode() : terminal(false) {
        //0으로 초기화 
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for(int i = 0; i < DIGIT; i++) {
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
    
    bool find(const char* key) {
        if(*key == 0) return true;
        int next = toNumber(*key);
        if(children[next] == NULL) return false;
        return children[next] -> find(key + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        TrieNode* Root = new TrieNode(); 
        int n; cin >> n;
        
        vector<string> v;
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            v.push_back(s);
        }
        sort(all(v), greater<>());
        
        bool ret = true;
        for(string s : v) {
            //cout << s << endl;
            
            if(Root->find(s.c_str())) {
                ret = false;
                break;
            } else {
                Root->insert(s.c_str());
            }
        }
        
        if(ret) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
