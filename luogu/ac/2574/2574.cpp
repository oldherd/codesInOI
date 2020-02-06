#include <cstdio>

using namespace std;

const int maxn = 200010;

struct stree{
	int l, r, val, laz, len;
}t[maxn<<2];

int a[maxn];

inline void getone(int &x) {
	char ch = getchar();
	while(ch != '0' && ch != '1') ch = getchar();
	if(ch == '1') x ^= 1;
}

inline void build(int p, int l, int r) {
	t[p].l = l; t[p].r = r; t[p].laz = 0; t[p].len = r - l + 1; 
	if(l == r) { t[p].val = a[l]; return; }
	int mid = (l + r) >> 1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
	t[p].val = t[p<<1].val + t[p<<1|1].val;
}

inline void spread(int p) {
	if(!t[p].laz) return;
	t[p<<1].val = t[p<<1].len - t[p<<1].val;
	t[p<<1|1].val = t[p<<1|1].len - t[p<<1|1].val; 
	t[p<<1].laz ^= 1; t[p<<1|1].laz ^= 1;
	t[p].laz ^= 1; 
}

inline void change(int p, int l, int r) {
	if(l <= t[p].l && t[p].r <= r) {
		t[p].val = t[p].r - t[p].l + 1 - t[p].val;
		t[p].laz ^= 1; 
		return;
	}
	spread(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) change(p<<1, l, r);
	if(r > mid) change(p<<1|1, l, r);
	t[p].val = t[p<<1].val + t[p<<1|1].val;
}

inline int query(int p, int l, int r) {
	if(l <= t[p].l && t[p].r <= r) { return t[p].val; }
	spread(p);
	int mid = (t[p].l + t[p].r) >> 1;
	int ans = 0;
	if(l <= mid) ans = query(p<<1, l, r);
	if(r > mid) ans += query(p<<1|1, l, r);
	return ans;
}

int main() {
	int n, m, op, l, r;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) getone(a[i]);
	build(1, 1, n);
	while(m--) {
		scanf("%d %d %d", &op, &l, &r);
		if(op == 0) change(1, l, r);
		else printf("%d\n", query(1, l, r)); 
	}
	return 0;
}
