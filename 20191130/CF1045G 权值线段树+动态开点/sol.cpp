#include <cstdio>
#include <algorithm>
#include <map>
#define itra map<int,int>::iterator
#define ll long long

using namespace std;

const int N = 100010, SIZE = N * 36;
int dat[SIZE], ls[SIZE], rs[SIZE], root[SIZE], tot = 1;
inline int newnode() {
	ls[tot] = rs[tot] = 0;
	return tot++;
}

inline void update(int p) {
	dat[p] = dat[ls[p]] + dat[rs[p]];
}

inline void insert(int p, int lp, int rp, int x) {
	if(lp == rp) {
		++dat[p];
		return;
	}
	int mid = (lp + rp) >> 1;
	if(x <= mid) {
		if(!ls[p]) ls[p] = newnode();
		insert(ls[p], lp, mid, x);
	} else {
		if(!rs[p]) rs[p] = newnode();
		insert(rs[p], mid + 1, rp, x);
	}
	update(p);
}

inline int qry(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return dat[p];
	int mid = (lp + rp) >> 1;
	int ans = 0;
	if(l <= mid && ls[p]) ans += qry(ls[p], lp, mid, l, r);
	if(r > mid && rs[p]) ans += qry(rs[p], mid + 1, rp, l, r);
	return ans;
}

struct Rob {
	int x, r, q;
	Rob() {}
	Rob(int X, int R, int Q): x(X), r(R), q(Q) {}
}rob[N];
bool cmp1(Rob a, Rob b) { return a.r > b.r; }
map<int, int> iqidx;
int iqval[N], iqnum;

int main() {
	int n, k, x, r, q, maxx = 0;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &x, &r, &q);
		rob[i] = Rob(x, r, q);
		iqval[i] = q;
		maxx = max(x, maxx);
	}
	sort(rob + 1, rob + n + 1, cmp1);
	sort(iqval + 1, iqval + n + 1);
	iqnum = unique(iqval + 1, iqval + n + 1) - iqval - 1;
	for(int i = 1; i <= iqnum; ++i) {
		root[i] = newnode();
		iqidx[iqval[i]] = i;
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		int qval = rob[i].q, qid = iqidx[qval];
		x = rob[i].x; r = rob[i].r;
		for(int i = qid; ~i && qval - iqval[i] <= k; --i) {
			ans += qry(root[i], 1, maxx, x - r, x + r);
		}
		for(int i = qid + 1; i <= iqnum && iqval[i] - qval <= k; ++i) {
			ans += qry(root[i], 1, maxx, x - r, x + r);
		}
		insert(root[qid], 1, maxx, x);
	}
	printf("%lld\n", ans);
	return 0;
}
