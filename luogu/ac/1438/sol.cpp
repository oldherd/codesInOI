#include <cstdio>

using namespace std;

const int maxn = 100010;
int a[maxn];

struct stree{
	private:
		int li[maxn<<2], ri[maxn<<2], val[maxn<<2], laz[maxn<<2];
		inline void spread(int p, int ll, int lr) {
			if(laz[p] == 0) return;
			val[p<<1] += ll * laz[p]; laz[p<<1] += laz[p];
			val[p<<1|1] += lr * laz[p]; laz[p<<1|1] += laz[p];
			laz[p] = 0;
		}
	public:
		inline void build(int p, int lp, int rp) {
			li[p] = lp; ri[p] = rp;
			if(lp == rp) { val[p] = 0; laz[p] = 0; return; }
			int mid = (lp + rp) >> 1;
			build(p<<1, lp, mid);
			build(p<<1|1, mid+1, rp);
			val[p] = 0; laz[p] = 0;
		}
		inline void change(int p, int l, int r, int v) {
			if(l <= li[p] && ri[p] <= r) {
				val[p] += (ri[p]-li[p]+1) * v;
				laz[p] += v;
				return;
			}
			int mid = (ri[p] + li[p]) >> 1;
			spread(p, mid-li[p]+1, ri[p]-mid);
			if(l <= mid) change(p<<1, l, r, v);
			if(r > mid) change(p<<1|1, l, r, v);
			val[p] = val[p<<1] + val[p<<1|1];
		} 
		inline int query(int p, int l, int r) {
			if(l <= li[p] && ri[p] <= r) return val[p];
			int mid = (ri[p] + li[p]) >> 1;
			spread(p, mid-li[p]+1, ri[p]-mid);
			int ans = 0;
			if(l <= mid) ans += query(p<<1, l, r);
			if(r > mid) ans += query(p<<1|1, l, r);
			return ans;
		}
}st;

int main() {
	int n, m, op, l, r, k, d;
	scanf("%d %d", &n, &m);
	for(register int i = 1; i <= n; i++) scanf("%d", a+i);
	st.build(1, 1, n+1);
	while(m--) {
		scanf("%d %d", &op, &l);
		if(op == 1) {
			scanf("%d %d %d", &r, &k, &d);
			st.change(1, l, l, k);
			if(r > l) st.change(1, l+1, r, d);
			st.change(1, r+1, r+1, -(r-l)*d-k);
		} else {
			printf("%d\n", st.query(1, 1, l) + a[l]);
		}
	}
	return 0;
}
