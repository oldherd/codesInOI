#include <cstdio>

using namespace std;

char buf[2000000], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin), p1==p2)?EOF:*p1++; }
inline void read(int &x) {
    x = 0;
    char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}

inline int qp(int b) {
	int res = 1, a = 2;
	for(;b;b>>=1) {
		if(b&1) res *= a;
		a *= a;
	}
	return res;
}

int main() {
	int n, l, r, mini, maxi;
	read(n); read(l); read(r);
	mini = qp(l) + n - l - 1;
	int d = qp(r);
	maxi = d + (d>>1) * (n-r) - 1;
	printf("%d %d\n", mini, maxi);
	return 0;
}


