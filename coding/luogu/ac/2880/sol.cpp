#include <cstdio>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f, maxn = 50010;
int a[maxn];

struct node{
	int mini, maxi;
	node() {}
	node(int A, int B) : mini(A), maxi(B) {}
	node operator + (const node& o) const {	return node(min(mini, o.mini), max(maxi, o.maxi)); }
	void operator += (const node& o) { *this = *this + o; }
}t[maxn<<2];

inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }

inline void build(int p, int lp, int rp) {
	if(lp == rp) { t[p].mini = t[p].maxi = a[lp]; return; }
	int mid = (lp + rp) >> 1;
	build(p<<1, lp, mid);
	build(p<<1|1, mid+1, rp);
	t[p] = t[p<<1] + t[p<<1|1];
}

inline node query(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return t[p];
	int mid = (lp + rp) >> 1;
	node pi(inf, -1);
	if(l <= mid) pi += query(p<<1, lp, mid, l, r);
	if(r > mid) pi += query(p<<1|1, mid+1, rp, l, r);
	return pi;
}

int main() {
	int n, q, t, g;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", a+i);
	build(1, 1, n);
	while(q--) {
		scanf("%d %d", &t, &g);
		node p = query(1, 1, n, t, g);
		printf("%d\n", p.maxi - p.mini);
	}
	return 0;
}
