#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 34567, INF = 0x3f3f3f3f;
int head[N], w[N], ver[N<<1], nex[N<<1], n, tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

int son[N], size[N], fa[N], dep[N], top[N], dfn[N], yl[N], dfs_clock = 1;
void dfs1(int cur, int pre) {
	size[cur] = 1; fa[cur] = pre; dep[cur] = dep[pre] + 1;
	for(int i = head[cur]; ~i; i = nex[i]) 
		if(ver[i] != pre) {
			dfs1(ver[i], cur);
			size[cur] += size[ver[i]];
			if(size[ver[i]] > size[son[cur]] || !son[cur]) {
				son[cur] = ver[i];
			}
		}
}
void dfs2(int cur, int tp) {
	yl[dfs_clock] = cur; dfn[cur] = dfs_clock++; top[cur] = tp;
	if(!son[cur]) return;
	dfs2(son[cur], tp);
	for(int i = head[cur]; ~i; i = nex[i]) 
		if(!dfn[ver[i]])
			dfs2(ver[i], ver[i]);
}

int dmax[N<<2], dsum[N<<2];
inline void update(int p) { 
	dmax[p] = max(dmax[p<<1], dmax[p<<1|1]);
	dsum[p] = dsum[p<<1] + dsum[p<<1|1];
}
void build(int p, int lp, int rp) {
	if(lp == rp) {
		dmax[p] = dsum[p] = w[yl[lp]];
		return;
	}
	int mid = (lp + rp) >> 1;
	build(p<<1, lp, mid);
	build(p<<1|1, mid + 1, rp);
	update(p);
}
void cgp(int p, int lp, int rp, int x, int v) {
	if(lp == rp) {
		dmax[p] = dsum[p] = v;
		return;
	}
	int mid = (lp + rp) >> 1;
	if(x <= mid) cgp(p<<1, lp, mid, x, v);
	else cgp(p<<1|1, mid + 1, rp, x, v);
	update(p);
}
int qrysum(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return dsum[p];
	int mid = (lp + rp) >> 1;
	int ans = 0;
	if(l <= mid) ans = qrysum(p<<1, lp, mid, l, r);
	if(r > mid) ans += qrysum(p<<1|1, mid + 1, rp, l, r);
	return ans;
}
int qrymax(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return dmax[p];
	int mid = (lp + rp) >> 1;
	int ans = -INF;
	if(l <= mid) ans = qrymax(p<<1, lp, mid, l, r);
	if(r > mid) ans = max(ans, qrymax(p<<1|1, mid + 1, rp, l, r));
	return ans;
}

inline int QMAX(int u, int v) {
	int ans = -INF;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		ans = max(ans, qrymax(1, 1, n, dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	return max(ans, qrymax(1, 1, n, dfn[v], dfn[u]));
}
inline int QSUM(int u, int v) {
	int ans = 0;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		ans += qrysum(1, 1, n, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	return ans + qrysum(1, 1, n, dfn[v], dfn[u]);
}

int main() {
	memset(head, -1, sizeof(head));
	int u, v, q;
	char str[8];
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		addedge(u, v); addedge(v, u);
	}
	for(int i = 1; i <= n; ++i) scanf("%d", w + i);
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	scanf("%d", &q);
	while(q--) {
		scanf("%s %d %d", str, &u, &v);
		if(str[0] == 'C') {
			cgp(1, 1, n, dfn[u], v);
		} else if(str[1] == 'M') {
			printf("%d\n", QMAX(u, v));
		} else if(str[1] == 'S') {
			printf("%d\n", QSUM(u, v));
		}
	}
	return 0;
}
