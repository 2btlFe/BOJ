#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a, b;
    cin >> a >> b;
    a = a - 1;
    
    long long int psum[55];
    psum[0] = 0;
    for(int i = 1; i <= 54; i++) {
        psum[i] = 2*psum[i-1] + pow(2, i-1);
    }

    vector<int> numA, numB;
    long long int retA = 0, retB = 0;
    
    for(int i = 0; i <= 54; i++) {
        int ai = (a>>i)&1;
        int bi = (b>>i)&1;
        
        if(ai) {
            retA += psum[i] + 1;
            numA .push_back(i);
        }
        
        if(bi) {
            retB += psum[i] + 1;
            numB .push_back(i);
        }
    }
    
    long long int sum = 0;
    int szA = (numA.size() - 1 < 0) ? 0 : numA.size() - 1;
    
    for(int i = 0; i < szA; i++) {
        sum += pow(2, numA[i]);
        retA += sum;
    }
    
    sum = 0;
    for(int i = 0; i < numB.size() - 1; i++) {
        sum += pow(2, numB[i]);
        retB += sum;
    }
    
    cout << retB - retA << endl;
}
