/*
boj 3197 Swan's Lake
time Complexity: O(r*c*a(r*c));
Explaination:
이 문제의 풀이는 워낙 다양하다
그 중, 나의 풀이는 
'BFS 두 번' + '2차원 배열 DSU' 로 풀었다
워낙 빡구현인 문제고,
다만, 내가 2차원 배열 DSU를 처음해보는 바람에 시간이 오래 걸렸다

int parent[1501][1501];
int getParent(int r, int c) {
    if(r*10000 + c == parent[r][c]) return parent[r][c];
    else return parent[r][c] = getParent(parent[r][c]/10000, parent[r][c]%10000);
}

void unionParent(int r1, int c1, int r2, int c2) {
    int p1 = getParent(r1, c1);
    int p2 = getParent(r2, c2);
    
    if(p1 < p2) {
        parent[p2/10000][p2%10000] = p1;
    } else {
        parent[p1/10000][p1%10000] = p2;
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array
#define endl "\n"

//ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/*
    ordered_set X;
    X.insert(2);
    X.insert(3);
    X.insert(5);
    cout << *X.find_by_order(1) << '\n'; //3의 위치
    cout << X.order_of_key(5) << '\n'; //2번째 값
*/


#define vt vector
#define pb push_back
#define pi pair<int, int> >;
#define pl pair<ll, ll> >;
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

//fo macro
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define fo(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}


/*read*/
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}


/*to_string*/
string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	fo(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	fo(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

/*write*/
template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

//dbg -> 미완성 
void DBG() {
	cout << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cout << to_string(h);
	if(sizeof...(t))
		cout << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cout << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif


//offset
template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}

//random
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}

//vti
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	EACH(a, v)
		vti(a, x, m);
}

//orient
const int d4[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
const int d8[8][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

char board[1501][1501];
int day[1501][1501];
int R, C;
queue<pair<int, int> > fq;
int l1r = -1, l1c, l2r, l2c;

int parent[1501][1501];
int getParent(int r, int c) {
    if(r*10000 + c == parent[r][c]) return parent[r][c];
    else return parent[r][c] = getParent(parent[r][c]/10000, parent[r][c]%10000);
}

void unionParent(int r1, int c1, int r2, int c2) {
    int p1 = getParent(r1, c1);
    int p2 = getParent(r2, c2);
    
    if(p1 < p2) {
        parent[p2/10000][p2%10000] = p1;
    } else {
        parent[p1/10000][p1%10000] = p2;
    }
}

void init_bfs(int r, int c) {
    queue<pair<int, int> > q;
    q.push({r, c});
    day[r][c] = 0;
    board[r][c] = 'C';
    
    while(!q.empty()) {
        int hr = q.front().first;
        int hc = q.front().second;
        q.pop();
        
        int flag = 0;
        for(int i = 0; i < 4; i++) {
            int tr = hr + d4[i][0];
            int tc = hc + d4[i][1];
            
            if(tr < 0 || tr >= R || tc < 0 || tc >= C || board[tr][tc] == 'C') continue;
            
            if(board[tr][tc] == 'X') {
                if(flag == 0) {fq.push({hr, hc}); flag = 1;}
                continue;
            }
            
            unionParent(hr, hc, tr, tc);
            q.push({tr, tc});
            board[tr][tc] = 'C';
            day[tr][tc] = 0;
        }
    }
    //cout << "\n";
}

int find_bfs() {
    int ret = 0;
    while(!fq.empty()) {
        int hr = fq.front().first;
        int hc = fq.front().second;
        
        fq.pop();
        
        for(int i = 0; i < 4; i++) {
            int tr = hr + d4[i][0];
            int tc = hc + d4[i][1];
            
            if(tr < 0 || tr >= R || tc < 0 || tc >= C || getParent(hr, hc) == getParent(tr, tc)) continue;
            
            if(board[tr][tc] == 'X') {
                board[tr][tc] = 'C'; 
                fq.push({tr, tc}); 
                day[tr][tc] = day[hr][hc] + 1;
            }
            
            unionParent(hr, hc, tr, tc);
            
            if(getParent(l1r, l1c) == getParent(l2r, l2c)) {
                return max(day[hr][hc], day[tr][tc]);
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(day, -1, sizeof(day));
    
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string s; cin >> s;
        for(int j = 0; j < C; j++) {
            board[i][j] = s[j];
            parent[i][j] = 10000*i + j;
            
            if(board[i][j] == 'L') {
                if(l1r == -1) {
                    l1r = i; l1c = j;
                } else {
                    l2r = i; l2c = j;
                }
            }
        }
    }
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == '.' || board[i][j] == 'L') {
                init_bfs(i, j);
            }
        }
    }
    
    cout << find_bfs();
}
