#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 50010, maxm = 50010;
int a[maxn], pos[maxn], c[maxn];
long long ans;

struct query{
	int l, r, id;
	long long ans;
	bool operator < (const query& o) const { return pos[l] == pos[o.l] ? r < o.r : l < o.l; }
}q[maxm];

inline void add(int pos) {
	ans -= (long long)c[a[pos]] * (c[a[pos]] - 1); c[a[pos]]++; ans += (long long)c[a[pos]] * (c[a[pos]] - 1);
}

inline void del(int pos) {
	ans -= (long long)c[a[pos]] * (c[a[pos]] - 1); c[a[pos]]--; ans += (long long)c[a[pos]] * (c[a[pos]] - 1);
}

inline bool cmp(query x, query y) {
	return x.id < y.id;
}

inline long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int block = (int)(n / sqrt((double)(m * 2/3)));
	for(int i = 1; i <= n; i++) pos[i] = i / block;
	for(int i = 1; i <= n; i++) scanf("%d", a+i);
	for(int i = 1; i <= m; i++) scanf("%d %d", &q[i].l, &q[i].r), q[i].id = i;
	sort(q+1, q+m+1);
	int l = 1, r = 0;
	for(int i = 1; i <= m; i++) {
		while(l < q[i].l) del(l++);
		while(l > q[i].l) add(--l);
		while(r < q[i].r) add(++r);
		while(r > q[i].r) del(r--);
		q[i].ans = ans;
	}
	sort(q+1, q+m+1, cmp);
	for(int i = 1; i <= m; i++) {
		if(q[i].l == q[i].r) {
			printf("0/1\n"); continue;
		}
		int len = q[i].r - q[i].l + 1;
		long long d = (long long)len * (len - 1);
		long long _g = gcd(d, q[i].ans);
		printf("%lld/%lld\n", q[i].ans / _g, d / _g);
	}
	return 0;
}
