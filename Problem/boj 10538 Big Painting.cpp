/*
boj 10538 Big Painting
Algorithm: Rabin_Karp + 2d_prefix_sum
TC: O(NM)
SC: O(NM)
Explaination:
kmp, rabin_karp, aho_korasic 등 
여러가지로 풀 수 있다



*/

#include <stdio.h>
#define ll long long

constexpr int MAX_R = 2000;
constexpr int MAX_C = 2000;
constexpr ll MOD = 1e9 + 7;

ll mod(ll x) {
    if(x >= 0) return x % MOD;
    else return ((-x / MOD + 1) * MOD + x) % MOD;
}

ll p_pow[MAX_R*MAX_C + 1];
void power_p() {
    int p = 5381;
    p_pow[0] = 1;
    for(int i = 1; i < MAX_R * MAX_C + 1; i++) {
        p_pow[i] = mod(p_pow[i-1] * p);
    }
}

ll psum[MAX_R + 1][MAX_C + 1];
ll nsum;
void psum_zero() {
    for(int i = 0; i < MAX_R + 1; i++) {
        for(int j = 0; j < MAX_C + 1; j++) {
            psum[i][j] = 0;
        }
    }    
}

int rabin_karp() {
    int H, W, N, M;
    scanf("%d %d %d %d ", &H, &W, &N, &M);
    char input;

    //hashing
    nsum = 0;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            scanf("%1c ", &input);
            nsum = mod(nsum + (input == 'o') * p_pow[i*M + j]); 
            
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%1c ", &input);
            psum[i][j] = mod(mod(mod(psum[i-1][j] + psum[i][j-1]) - psum[i-1][j-1]) + (input == 'o') * p_pow[i*M + j]); 
        }
    }
    
    //확인하기 
    ll cnt = 0;
    for(int i = H; i <= N; i++) {
        for(int j = W; j <= M; j++) {
            ll tmp = mod(mod(mod(psum[i][j] - psum[i-H][j]) - psum[i][j-W]) + psum[i-H][j-W]);
            ll cmp = mod(nsum * p_pow[(i-H)*M + (j-W)]);
            if(cmp == tmp) cnt++;
        }
    }
    return cnt;
}

int main() {
    power_p();
    psum_zero();
    int tc; scanf("%d", &tc);
    for(int t = 1; t <= tc; t++) {
        printf("#%d %lld\n", t, rabin_karp());
    }
    return 0;
}
