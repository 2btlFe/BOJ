/*
TC: O(logN)
*/
int gcd(int a, int b) {
    if(a % b == 0) return b;
    return gcd(b, a%b);
}

int gcd_iter(int a, int b) {
    if(a < b) swap(a, b);
    while(b != 0) {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}
