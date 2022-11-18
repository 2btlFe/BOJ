/*
프로그래머스 level4 가사 검색
Algorithm: 
TC: O(N|S|)
SC: 
노드 개수: 10^6
포인터 배열 크기: 26
포인터 크기 : 8
약 10^8
Explaination:

1) prefix Trie와 suffix Trie를 만들어 둔다
2) 각 노드에 남은 길이 별 개수를 담은 map을 둔다
3) insert로 Trie를 만들어 둔다
4) find로 '?'나 끝에 도달할 때까지 재귀를 한다 
*/

#include <bits/stdc++.h>

using namespace std;

const int ALPHABET = 26;
int toNumber(char ch) {return ch - 'a';}

struct TrieNode{
    map<int, int> num;    
    TrieNode* children[ALPHABET];
    
    TrieNode() {
        memset(children, 0, sizeof(children));
    }
    
    ~TrieNode() {
        num.clear();
    }
    
    void insert(const char* key, int rest) {
        num[rest]++;
        if(*key == 0) return;
        
        int next = toNumber(*key);
        if(children[next] == NULL) 
            children[next] = new TrieNode();
        children[next] -> insert(key + 1, rest-1); 
    }
    
    int find(const char* key, int rest) {
        if(*key == '?' || *key == 0) { 
            return num[rest];  
        }    
        int next = toNumber(*key);
        if(children[next] == NULL) return 0;
        return children[next] -> find(key + 1, rest-1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    TrieNode* Prefix = new TrieNode();
    TrieNode* Suffix = new TrieNode();
    
    for(string st : words) {
        Prefix->insert(st.c_str(), st.size());
        reverse(st.begin(), st.end());
        Suffix->insert(st.c_str(), st.size());
    }
    
    for(string query : queries) {
        int ans = 0;
        if(query[0] == '?') {
            reverse(query.begin(), query.end());
            ans = Suffix->find(query.c_str(), query.size());
        } else {
            ans = Prefix->find(query.c_str(), query.size());
        }
        //cout << ans << endl;
        answer.push_back(ans);
    }
    
    
    
    return answer;
}
