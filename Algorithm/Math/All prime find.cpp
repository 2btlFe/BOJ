//TC: O(nlog(logn))

const int N = 1e6 + 6;
vector<int> isprime(N, 1); 
vector<int> sprime;
 
void seive(int n) {
    isprime[0] = isprime[1] = 0;
    //sprime.push_back(0);
    for(int i = 2; i <= n; i++) {
        if(isprime[i]) {
            sprime.push_back(i);
            for(int j = i*i; j <= n; j+=i) {
                isprime[j]=0;
            }
        }
    }
}
