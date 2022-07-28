/*
boj 1893 Caesar cipher
Algorithm: KMP
Time_Complexity:O(|A| *(|W| + |S|)) 60 *(550000) -> 30ms
Explain:

나의 경우 그냥 나머지 연산을 통해 순회를 하였다
직접 문자열을 바꾸는 방법은 -> map을 이용하여, 
s[i] = s[m[i]] 이런 식으로, parent 찾아주기 같이 
바꾸면 된다
*/



#include<bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int aSize;

vector<int> getPartialMatch(const vector<int>& N, int x) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while(begin + matched < m) {
        if((N[begin + matched] + x) % aSize == (N[matched] + x) % aSize) {
            matched++;
            pi[begin + matched - 1] = matched;
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

bool kmpSearch(const vector<int> H, const vector<int>& N, int x) {
    int n = H.size();
    int m = N.size();
    vector<int> pi = getPartialMatch(N, x);
    bool ret = false;
    int begin = 0, matched = 0;
    while(begin <= n - m) {
        if(matched < m && H[begin + matched] == (N[matched] + x) % aSize) {
            matched++;
            if(matched == m) {
                if(ret == true) {
                    return false;
                } else {
                    ret = true;
                }
            }
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int T; cin >> T;
    
    while(T--) {
        string A, W, S;
        cin >> A >> W >> S;
        
        aSize = A.size();
        
        //hashing
        map<char, int> m;
        for(int i = 0; i < aSize; i++) {
            m[A[i]] = i;
        }
        
        //W변경
        vector<int> nW;
        for(char ch : W) {
            nW.push_back(m[ch]);
        }
        
        vector<int> nS;
        for(char ch : S) {
            nS.push_back(m[ch]);
        }
        
        set<int> ans;
        for(int x = 0; x < A.size(); x++) {
            if(kmpSearch(nS, nW, x)) {
                ans.insert(x);
            }
        }
        
        if(ans.size() == 0) {
            cout << "no solution" << endl;
        } else if(ans.size() == 1) {
            cout << "unique: " << *ans.begin() << endl;
        } else{
            cout << "ambiguous: ";
            for(int i : ans) cout << i << " ";
            cout << endl;
        }    
    }
}






