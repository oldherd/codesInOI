#include <cstdio>

using namespace std;

const int sz = 2000000, maxn = 200010;
char buf[sz], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,sz,stdin), p1==p2)?EOF:*p1++; }
#define gc() getchar()
inline void read(int &x) {
    x = 0;
    int f = 1;
    char ch = gc();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = gc(); }
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
    x *= f;
}

int ai[maxn], pp[maxn], pu;

inline long long min(long long a, int b) { return a < b ? a : (long long)b; }

int main() {
	int t, n, a, b;
	long long cost;
	char ch;
	read(t);
	while(t--) {
		pu = 0;
		read(n); read(a); read(b);
		cost = a*(long long)n;
		ch = gc();
		while(ch != '0' && ch != '1') ch = gc();
		ai[0] = ch&15;
		for(int i = 1; i < n; i++) ai[i] = gc()&15;
		if(ai[0] == 1) pp[pu++] = 0;
		int lst = ai[0], len = 1;
		for(int i = 1; i < n; i++)	{
			if((ai[i-1] || ai[i])) {
				if(lst) len++;
				else {
					pp[pu++] = len;
					lst = 1; len = 1;	
				}
			} else {
				if(!lst) len++;	
				else {
					pp[pu++] = len;
					lst = 0; len = 1;	
				}
			}
		}
		if(ai[n] == lst) pp[pu++] = len+1;
		else pp[pu++] = len, pp[pu++] = 1;
		for(int i = 0; i < pu; i++)
			cost += (long long)b * (i%2?(pp[i]<<1):pp[i]);
		for(int i = 0; i < pu; i += 2) {
			if(!pp[i]) continue;
			if(i+1==pu && i==0) continue;
			if(i+1 == pu || i==0) cost += min(pp[i]*(long long)b, a);
			else cost += min(pp[i]*(long long)b, a*2);
		}
		printf("%lld\n", cost);
	}
	return 0;
}

