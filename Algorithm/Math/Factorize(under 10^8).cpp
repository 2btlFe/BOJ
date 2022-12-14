/*
에라토스테네스의 체는 O(nlog(logn))
소인수 분해는 O(logn)
*/

const ll N = 1e7+5;
vector<ll> spf(N+1, 1); //smallest prime factor

void sieve() { //O(Nlog(logN))
    for(ll i = 2; i <= N; i++) {
        if(spf[i] == 1) {
            spf[i] = i;
            for(ll j = i*i; j <= N; j += i) {
                if(spf[j] == 1) spf[j] = i;
            }
        }
    }
}

vector<ll> factorize(ll n) { //O(logN)
    vector<ll> v;
    while(n > 1)
    {
        ll fact = spf[n];
        while(n % fact == 0) {
            n /= fact;
        }
        v.push_back(fact);
    }
    return v;
}
