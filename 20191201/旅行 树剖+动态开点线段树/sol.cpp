#include <cstdio>

using namespace std;

const int N = 100010, SIZE = 20 * N;

int head[N], ver[N<<1], nex[N<<1], tot1 = 0, n;
inline void addedge(int u, int v) {
	ver[tot1] = v; nex[tot1] = head[u]; head[u] = tot1++;
}

int root[N], dmax[SIZE], dsum[SIZE], ls[SIZE], rs[SIZE], tot = 1;
inline int newnode() { ls[tot] = rs[tot] = dmax[tot] = dsum[tot] = 0; return tot++; }
inline void update(int p) { dmax[p] = max(dmax[ls[p]], dmax[rs[p]]); dsum[p] = dsum[ls[p]] + dsum[rs[p]]; }
inline void assign(int p, int lp, int rp, int x, int v) {
	if(lp == rp) {
		dmax[p] = dsum[p] = v;
		return ;
	}
	int mid = (lp + rp) >> 1;
	if(x <= mid) {
		if(!ls[p]) ls[p] = newnode();
		assign(ls[p], lp, mid, x, v);
	} else {
		if(!rs[p]) rs[p] = newnode();
		assign(rs[p], mid + 1, rp, x, v);
	}
	update(p);
}
inline int qrymax(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return dmax[p];
	int mid = (lp + rp) >> 1;
	int ans = 0;
	if(l <= mid && ls[p]) ans = max(ans, qrymax(ls[p], lp, mid, l, r));
	if(r > mid && rs[p]) ans = max(ans, qrymax(rs[p], mid + 1, rp, l, r));
	return ans;
}
inline int qrysum(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return dsum[p];
	int mid = (lp + rp) >> 1;
	if(l <= mid && ls[p]) ans += qrysum(ls[p], lp, mid, l, r);
	if(r > mid && rs[p]) ans += qrysum(rs[p], mid + 1, rp, l, r);
	return ans;
}

int dfn[N], son[N], size[N], top[N], fa[N], dep[N], yl[N], dfs_clock = 1;
void dfs1(int cur, int pre) {
	fa[cur] = pre; dep[cur] = dep[pre] + 1; size[cur] = 1;
	for(int i = head[cur]; ~i; i = nex[i]) 
		if(ver[i] != pre) {
			dfs1(ver[i], cur);
			size[cur] += size[ver[i]];
			if(!son[cur] || size[son[cur]] < size[ver[i]])
				son[cur] = ver[i];
		}
}
void dfs2(int cur, int tp) {
	yl[dfs_clock] = cur; dfn[cur] = dfs_clock++; top[cur] = tp;
	if(!son[cur]) continue;
	dfs2(son[cur], tp);
	for(int i = head[cur]; ~i; i = nex[i]) 
		if(!dfn[ver[i]])
			dfs2(ver[i], ver[i]);
}
int getsum(int root, int u, int v) {
	int ans = 0;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		ans += qrysum(root, 1, n, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	return ans + qrysum(root, 1, n, dfn[v], dfn[u]);
}
int getmax(int root, int u, int v) {
	
}

int c[N], w[N];
int main() {
	int q, u, v, w, maxc = 0;
	char str[5];
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", c + i, w + i);
		maxc = max(c, maxc);
	}
	for(int i = 1; i < n; ++i) {
		scanf("%d %d %d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	for(int i = 1; i <= maxc; ++i) root[i] = newnode();
	for(int i = 1; i <= n; ++i) 
		assign(root[c[i]], 1, n, dfn[i], w[i]);
	while(q--) {
		scanf("%s %d %d", str, &u, &v);
		if(str[0] == 'C') {
			if(str[1] == 'C') {
				assign(root[c[u]], 1, n, dfn[u], 0);
				assign(root[v], 1, n, dfn[u], w[u]);
				c[u] = v;
			} else {
				assign(root[c[u]], 1, n, dfn[u], v);
				w[u] = v;
			}
		} else {
			if(str[1] == 'S') {
				printf("%d\n", getsum(root[u], u, v));
			} else {
				printf("%d\n", getmax(root[u], u, v));
			}
		}
	}
	return 0;
}
