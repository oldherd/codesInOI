#include <cstdio>
#include <algorithm>
#define ull unsigned long long

using namespace std;

const ull INF = 9e18;
const int N = 1234567;
ull a[N];

char buf[1<<20], *p1, *p2;
inline char gc() {
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++;
}

inline ull read() {
	char ch = gc(); ull x = 0;
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
	return x;
}

int main() {
	freopen("inputA.in", "r", stdin);
	int n, r;
	n = read(), r = read();
	--n;
	for(int i = 1; i <= n; ++i) {
		a[i] = read(), a[i] += a[i-1];
	}
	if(r >= n) {
		printf("0\n");
	} else {
		ull ans = INF;
		int ed = n - r + 1;
		for(int i = 1; i <= ed; ++i) {
			ans = min(ans, a[n] - a[i+r-1] + a[i-1]);
		}
		printf("%llu", ans);
	}
	return 0;
}
