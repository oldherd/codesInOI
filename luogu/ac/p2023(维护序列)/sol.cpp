#include <cstdio>

using namespace std;

const int maxn = 100010;

long long pn;
int a[maxn], n;

struct stree{
	int l, r;
	long long val, lax, lay;
	#define lp t[p].l
	#define rp t[p].r
	#define len(p) (t[p].r-t[p].l+1)
}t[maxn<<2];

inline void build(int p, int ll, int rr) {
	t[p].l = ll; t[p].r = rr; t[p].lax = 0; t[p].lay = 1;
	if(ll == rr) {
		t[p].val = a[lp] % pn;
		return;
	}
	int mid = (ll + rr) >> 1;
	build(p<<1, ll, mid);
	build(p<<1|1, mid+1, rr);
	t[p].val = (t[p<<1].val + t[p<<1|1].val) % pn;
}

inline void spread(int p) {
	long long &lax = t[p].lax, &lay = t[p].lay;
	if(lax == 0 && lay == 1) return;
	t[p<<1].val = (t[p<<1].val * lay + lax * len(p<<1)) % pn;
	t[p<<1|1].val = (t[p<<1|1].val * lay + lax * len(p<<1|1)) % pn;
	t[p<<1].lax = (t[p<<1].lax * lay + lax)%pn; t[p<<1].lay = t[p<<1].lay * lay % pn;
	t[p<<1|1].lax = (t[p<<1|1].lax * lay + lax) % pn; t[p<<1|1].lay = t[p<<1|1].lay * lay % pn; 
	lax = 0; lay = 1;
}

inline void addx(int p, int l, int r, int x) {
	if(l <= lp && rp <= r) {
		t[p].val = (len(p)*x + t[p].val) % pn;
		t[p].lax = (t[p].lax + x) % pn;
		return;
	}
	spread(p);
	int mid = (lp + rp) >> 1;
	if(l <= mid) addx(p<<1, l, r, x);
	if(r > mid) addx(p<<1|1, l, r, x);
	t[p].val = (t[p<<1].val + t[p<<1|1].val) % pn;
}

inline void addy(int p, int l, int r, int y) {
	if(l <= lp && rp <= r) {
		t[p].val = t[p].val * y % pn;
		t[p].lay = t[p].lay * y % pn;
		t[p].lax = t[p].lax * y % pn;
		return; 
	}
	spread(p);
	int mid = (lp + rp) >> 1;
	if(l <= mid) addy(p<<1, l, r, y);
	if(r > mid) addy(p<<1|1, l, r, y);
	t[p].val = (t[p<<1].val + t[p<<1|1].val) % pn;
}

inline long long query(int p, int l, int r) {
	if(l <= lp && rp <= r) return t[p].val;
	spread(p); 
	int mid = (lp + rp) >> 1;
	long long ans = 0;
	if(l <= mid) ans = query(p<<1, l, r);
	if(r > mid) ans += query(p<<1|1, l, r);
	return ans % pn;
}
/*
void tree() {
	printf("\n#############################################\n");
	int p = 1;
	register int l;
	for(l = 1; l < n; l<<=1) {
		while(p < l) printf("(%d %d %lld %lld %lld) ", t[p].l, t[p].r, t[p].val, t[p].lax, t[p].lay), p++;
		printf("\n");
	}
	while(p < l) printf("(%d %d %lld %lld %lld) ", t[p].l, t[p].r, t[p].val, t[p].lax, t[p].lay), p++;
	printf("\n");
	l <<= 1;
	while(p < l) printf("(%d %d %lld %lld %lld) ", t[p].l, t[p].r, t[p].val, t[p].lax, t[p].lay), p++;
	printf("\n");
	printf("\n#############################################\n\n");
}
*/
int main() {
	int m, op, t, g, c;
	scanf("%d %lld", &n, &pn);
	for(int i = 1; i <= n; i++) scanf("%d", a+i);
	build(1, 1, n);
	scanf("%d", &m);
	while(m--) {
		scanf("%d %d %d", &op, &t, &g);
		if(op != 3) scanf("%d", &c);
		if(op == 1) {
			addy(1, t, g, c);
		} else if(op == 2) {
			addx(1, t, g, c);
		} else {
			printf("%lld\n", query(1, t, g));
		}
	}
	return 0;
}
