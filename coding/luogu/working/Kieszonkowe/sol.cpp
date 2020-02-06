#include <cstdio>

using namespace std;

inline char gc() {
	static char buf[2000000], *p1 = buf, *p2 = buf;
	return p1==p2 && (p2=(p1=buf)+fread(buf, 1, 2000000, stdin), p1==p2) ? EOF : *p1++;
}

inline void read(int &x) {
    x = 0;
    char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}

int main() {
	int n, sum, mini = 0x3f3f3f3f, a, ct = 0;
	read(n);
	for(int i = 1; i <= n; i++) {
		read(a);
		if(a % 2) { mini = mini < a ? mini : a; ct ^= 1; }
		sum += a;
	}
	if(ct) sum -= mini;
	printf("%d\n", sum);
	return 0;
}
