#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010, maxm = 500010, maxq = 500010;
int a[maxn], rnk[maxn], rnans[maxq], fa[maxn], ans[maxq];


struct edge{
	int u, v, w;
	bool operator < (const edge& o) const { return w < o.w; }
}e[maxm];

struct ask{
	int v, x, k;
}as[maxq];

bool cmp1(int i, int j) {
	return a[i] > a[j];
} 

bool cmp2(int i, int j) {
	return as[i].x < as[j].x;	
}

inline int get(int x) {
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

inline void mg(int x, int y) {
	x = get(x); y = get(y);
	fa[y] = x;	
}

struct stree{
	int ls, rs, val;
}t[30*maxm];
int root[maxn], tot = 1;

inline int newnode() {
	t[tot].ls = t[tot].rs = t[tot].val = 0;
	return tot++;
}

inline void insert(int p, int lp, int rp, int pls) {
	if(lp == rp) { t[p].val++; return; }
	int mid = (lp + rp) >> 1;
	if(pls <= mid) {
		if(!t[p].ls) t[p].ls = newnode();
		insert(t[p].ls, lp, mid, pls);
	} else {
		if(!t[p].rs) t[p].rs = newnode();
		insert(t[p].rs, mid+1, rp, pls);
	}
	t[p].val = t[t[p].ls].val + t[t[p].rs].val;
}

inline int merge(int p, int q, int lp, int rp) {
	if(!p || !q) return p|q;
	if(lp == rp) { t[p].val += t[q].val; return p; }
	int mid = (lp + rp) >> 1;
	t[p].ls = merge(t[p].ls, t[q].ls, lp, mid);
	t[p].rs = merge(t[p].rs, t[q].rs, mid+1, rp);
	t[p].val = t[t[p].ls].val + t[t[p].rs].val;
	return p;
}

inline int query(int p, int lp, int rp, int k) {
    if(lp == rp) return lp;
    int mid = (lp + rp) >> 1;
    if(t[t[p].ls].val >= k) return query(t[p].ls, lp, mid, k);
    else return query(t[p].rs, mid+1, rp, k-t[t[p].ls].val);
}

//#############################################
void tree(int p, int lp, int rp) {
	printf("(%d %d %d)\n", lp, rp, t[p].val);
	int mid = (lp + rp) >> 1;
	if(t[p].ls) tree(t[p].ls, lp, mid);
	if(t[p].rs) tree(t[p].rs, mid+1, rp);
}
//#############################################

int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i++) scanf("%d", a+i), rnk[i] = fa[i] = i;
	sort(rnk+1, rnk+n+1, cmp1);
	for(int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	sort(e+1, e+m+1);
	for(int i = 1; i <= q; i++) scanf("%d %d %d", &as[i].v, &as[i].x, &as[i].k), rnans[i] = i;
	sort(rnans+1, rnans+q+1, cmp2);
	int p = 1;
	for(int i = 1; i <= n; i++) {
		root[rnk[i]] = newnode();
		insert(root[rnk[i]], 1, n, i);
		/*
		printf("i == %d, rnk[i] = %d.#############\n", i, rnk[i]);
		tree(root[rnk[i]], 1, n);
		printf("################################\n\n");
		*/
		
	}
	for(int i = 1; i <= q; i++) {
		int v = as[rnans[i]].v, x = as[rnans[i]].x, k = as[rnans[i]].k;
		while(e[p].w <= x && p <= m) {
			if(get(e[p].u) == get(e[p].v)) { p++; continue;}
			root[e[p].u] = root[e[p].v] = merge(root[get(e[p].u)], root[get(e[p].v)], 1, n);
			mg(e[p].u, e[p].v);
			p++;
		}
		/*
		printf("####################%d######################\n", i);
		tree(root[get(v)], 1, n);
		printf("###########################################\n");
		*/
		v = get(v);
		if(t[root[v]].val < k) ans[rnans[i]] = -1;
		else ans[rnans[i]] = a[rnk[query(root[v], 1, n, k)]];
	}
	for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}
