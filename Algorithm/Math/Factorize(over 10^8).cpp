

const int N = 1e6 + 6;
vector<ll> isprime(N, 1); 
vector<ll> sprime;
 
//O(nloglogn)
void seive(ll n) {
    isprime[0] = isprime[1] = 0;
    //sprime.push_back(0);
    for(ll i = 2; i <= n; i++) {
        if(isprime[i]) {
            sprime.push_back(i);
            for(ll j = i*i; j <= n; j+=i) {
                isprime[j]=0;
            }
        }
    }
}
 
//O(len(prime)) 
vector<ll> factorize(ll n) {
    ll fact = n;
    vector<ll> pf;
    for(int j = 0; j < sprime.size(); j++) {
        if(fact%sprime[j] == 0) {
            pf.push_back(sprime[j]);
            while(fact%sprime[j] == 0) {
                fact/=sprime[j];
            } 
        }
    }
    //sqrt(n)보다 큰 소수여서 소인수 분해가 되지 않으면 그냥 소수로 넣어준다
    if(fact != 1) {
        pf.push_back(fact);
    }
    return pf;
}

