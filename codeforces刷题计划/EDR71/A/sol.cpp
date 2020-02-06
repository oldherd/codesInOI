#include <cstdio>

using namespace std;

char buf[2000000], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin), p1==p2)?EOF:*p1++; }
inline void read(int &x) {
    x = 0; char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}
inline int min(int x, int y) { return x < y ? x : y; }
int main() {
	int t, b, p, f, h, c;
	read(t);
	while(t--) {
		read(b); read(p); read(f);
		read(h); read(c);
		if(h < c) h^=c^=h^=c, p^=f^=p^=f;
		if((p<<1) > b) {
			printf("%d\n", h*(b>>1));	
		} else {
			printf("%d\n", h*p+c*min((b-(p<<1))>>1, f));
		}
	}
	return 0;
}


