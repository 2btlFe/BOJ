#include<bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;


//O(H)
vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while(begin + matched < m) {
        if(N[begin + matched] == N[matched]) {
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

//O(N)
vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int begin = 0, matched = 0;
    while(begin <= n - m) {
        if(matched < m && H[begin + matched] == N[matched]) {
            matched++;
            if(matched == m) ret.push_back(begin);
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


int aSize;

vector<int> getPartialMatch(vector<int>& N, int x) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while(begin + matched < m) {
        if((N[begin + matched] + x) % aSize == N[matched]) {
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
        if(matched < m && H[begin + matched] == N[matched]) {
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
}

int main() {
    
    int T; cin >> T;
    
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
        cout << "unique: " << ans[0] << endl;
    } else{
        cout << "ambiguous: ";
        for(int i : ans) cout << i << " ";
        cout << endl;
    }
}







