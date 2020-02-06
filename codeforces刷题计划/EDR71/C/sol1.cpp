#include <cstdio>

using namespace std;

const int maxn = 200010;
char buf[2000000], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin), p1==p2)?EOF:*p1++; }
#define gc() getchar()
inline void read(int &x) {
    x = 0; char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}

int p[maxn], pu;
inline long long min(long long x, long long y) { return x < y ? x : y; }

int main() {
	long long cost;
	int t, n, a, b, plr, len;
	char ch, lst;
	read(t);
	while(t--) {
		read(n); read(a); read(b); ch = gc();
		while(ch != '0' && ch != '1') ch = gc();
		plr = (ch&15)+1; pu = 0;
		if(ch&15) p[pu++] = 0;
		len = 1; lst = ch;
		for(int i = 1; i < n; i++) {
			ch = gc();
			if((lst&15) || (ch&15)) plr += 2;
			else plr += 1;
			if(ch==lst) len++;
			else {
				p[pu++] = len;
				lst = ch;
				len = 1;	
			}
		}
		plr += (lst&15)+1;
		p[pu++] = len;
		cost = (long long)plr * b + n * (long long)a;
		if(pu==1 || (pu==2&&p[0]==0)) {
			printf("%lld\n", cost);
			continue;	
		}
		for(int i = 0; i < pu; i+=2) {
			if(!p[i]) continue;
			if(i==0 || i+1==pu) cost += min((long long)a, p[i]*(long long)b);
			else cost += min((long long)a*2, (long long)b*(p[i]-1));
		}
		printf("%lld\n", cost);
	}
	return 0;
}


