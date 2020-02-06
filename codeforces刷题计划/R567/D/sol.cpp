#include <cstdio>
#include <algorithm>
#define ull unsigned long long
 
using namespace std;
 
const int maxtt = 500010, inf = 2147483647, maxn = 500010;
 
namespace fastio{
    const int L = 1<<15;
    char buffer[L],*S,*T;
    inline char Getchar(){
        if(S == T){
            T = (S=buffer) + fread(buffer,1,L,stdin);
            if(S == T) return EOF;
        }
        return *S++;
    }
    template <class T> inline void read(T &in){
        char c;int f = 1;
        for(c = Getchar();c > '9' || c < '0';c = Getchar());
        for(in = 0;c >= '0' && c <= '9';c = Getchar()) in = (in<<1) + (in<<3) + c - '0';
        in *= f;
    }   
}
 
struct Splay{
    int root, tot, maxi;
    int ch[maxtt][2], fa[maxtt], size[maxtt];
    int val[maxtt], cnt[maxtt];
    Splay() { root = 0; tot = 1; insert(-inf); insert(inf); maxi = 0;}
    int newnode(int v, int f) {
		ch[tot][0] = ch[tot][1] = 0; fa[tot] = f;
		size[tot] = cnt[tot] = 1; val[tot] = v; return tot++;
    }
    int chr(int x) { return ch[fa[x]][1] == x; }
    void update(int x) { size[x] = cnt[x] + size[ch[x][1]] + size[ch[x][0]]; }
    void rotate(int x) {
		int y = fa[x], z = fa[y], k = chr(x), m = ch[x][k^1];
		ch[y][k] = m; fa[m] = y;
		ch[z][chr(y)] = x; fa[x] = z;
		ch[x][k^1] = y; fa[y] = x;
		update(y); update(x);
    }
    void splay(int x, int to = 0) {
		while(fa[x] != to) {
		    if(fa[fa[x]] != to) rotate(chr(x)==chr(fa[x])?fa[x]:x);
		    rotate(x);
		}
		if(!to) root = x;
    }
    void insert(int v) {
		int cur = root;
		while(ch[cur][v>val[cur]] && v != val[cur]) cur = ch[cur][v>val[cur]];
		if(v == val[cur]) cnt[cur]++;
		else cur = ch[cur][v>val[cur]] = newnode(v, cur);
		splay(cur); maxi = max(maxi, v);
    }
    int kth(int k) {
		int cur = root; ++k;
		while(true)
		    if(size[ch[cur][0]] >= k) cur = ch[cur][0];
		    else if(size[ch[cur][0]]+cnt[cur] >= k)  return val[cur];
		    else k -= size[ch[cur][0]]+cnt[cur], cur = ch[cur][1];
    }
}s;
 
int a[maxn], rnk[maxn], rq[maxn], ans[maxn];
ull qry[maxn], wt[maxn];
inline bool cmp(int x, int y) { return a[x]==a[y]?x<y:a[x]<a[y]; }
inline bool cmp2(int x, int y) { return qry[x]<qry[y]; }
 
inline int bound(int l, int r, ull x) {
	int mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(wt[rnk[mid]] <= x) l = mid;
		else r = mid - 1;
	}
	return l;
}
 
int main() {
	int n, m, q, pls, last = 0;
	fastio::read(m); fastio::read(n); fastio::read(q);
	for(int i = 1; i <= m; i++) {
		fastio::read(pls); a[pls]++;
	}
	for(int i = 1; i <= n; i++) rnk[i] = i;
	sort(rnk+1, rnk+n+1, cmp);
	wt[rnk[1]] = 0;
	for(int i = 2; i <= n; i++)
		wt[rnk[i]] = wt[rnk[i-1]] + (ull)(a[rnk[i]]-a[rnk[i-1]])*(i-1);
	for(int i = 1; i <= q; i++) fastio::read(qry[i]), rq[i] = i;
	sort(rq, rq+q+1, cmp2);
	for(int i = 1; i <= q; i++) {
		ull qr = qry[rq[i]]; qr -= m;
		if(qr <= wt[rnk[n]]) {
			int p = bound(1, n, (ull)qr), q = bound(1, n, (ull)qr-1);
			for(int j = last+1; j <= q; j++) s.insert(rnk[j]);
			if(qr == wt[rnk[p]]) last = q;
			else {
				last = p;
				for(int j = q+1; j <= p; j++) s.insert(rnk[j]);
			}
			qr -= wt[rnk[p]];
			if(!qr) ans[rq[i]] = s.maxi;
			else ans[rq[i]] = s.kth(!(qr%last)?last:(qr%last));
		} else {
			ans[rq[i]] = (qr-wt[rnk[n]]) % n;
			if(!ans[rq[i]]) ans[rq[i]] = n;	
		}
	}
	for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}

