/*
boj 1498 주기문
Algorithm: KMP(Failure Function)
Time_Complexity: O(|S|)
Explaination {
    
    지금 까지 나온 문자열에서 
    구할 수 있는 최소 크기로 주기를 만들 수 문자열은
    
    Minstring  = idx + 1 -(failure Funcion(idx))
    if(pi[i] % (i + 1 - pi[i]) == 0)
        Cycle = (i+1) / Minstring; 
    최소 크기의 주기를 만들 수 있는 문자열이
    만들어내는 주기는 최대이다.
    
    주기랑 관련이 있으면 
    되도록 idx + 1 - pi[i]를 하자
}

*/
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    vector<int> pi = getPartialMatch(s);
    
    int tmp = 0;
    for(int i = 0; i < pi.size(); i++) {
        if(pi[i] % (i + 1 - pi[i]) == 0) {
            int cycle = pi[i] / (i + 1 - pi[i]) + 1;
            if(cycle == 1) continue;

            cout << i + 1 << " " << cycle << endl;
        }
    }
}
