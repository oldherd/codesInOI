#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

const int inf = 0x3f3f3f3f, N = 56789, M = 123456;
struct edge{
	int u, v, w, intree;
}ed[M];
bool cmp1(edge a, edge b) { return a.w < b.w; }

int head[N], ver[N<<1], wei[N<<1], nex[N<<1], tot, n;
inline void addedge(int u, int v, int w) {
	ver[tot] = v, wei[tot] = w, nex[tot] = head[u], head[u] = tot++;
}

int fat[N];
int find(int x) { return x == fat[x] ? x : fat[x] = find(fat[x]); }

int dfn[N], top[N], size[N], son[N], yl[N], dep[N], fa[N], we[N], dfs_clock = 1;
void dfs1(int cur, int pre, int wto) {
	size[cur] = 1; dep[cur] = dep[pre] + 1; fa[cur] = pre; we[cur] = wto;
	for(int i = head[cur]; ~i; i = nex[i])
		if(ver[i] != pre) {
			dfs1(ver[i], cur, wei[i]);
			size[cur] += size[ver[i]];
			if(size[son[cur]] < size[ver[i]] || !son[cur])
				son[cur] = ver[i];
		}
}
void dfs2(int cur, int tp) {
	yl[dfs_clock] = cur; dfn[cur] = dfs_clock++;
	if(!son[cur]) return;
	dfs2(son[cur], tp);
	for(int i = head[cur]; ~i; i = nex[i])
		if(!dfn[ver[i]])
			dfs2(ver[i], ver[i]);
}

struct node {
	int m1, m2;
	node() { m1 = m2 = inf;}	
}dat[N<<2];
node merge(node a, node b) {
	node o;
	if(a.m1 > b.m1) swap(a, b);
	o.m1 = a.m1;
	if(a.m1 == b.m1) o.m2 = min(a.m2, b.m2);
	else o.m2 = min(a.m2, b.m1);
	return o;
}
void update(int p) { dat[p] = merge(dat[p<<1], dat[p<<1|1]); }
void build(int p, int lp, int rp) {
	if(lp == rp) {
		dat[p].m1 = we[yl[lp]];
		return ;
	}
	int mid = (lp + rp) >> 1;
	build(p<<1, lp, mid);
	build(p<<1|1, mid + 1, rp);
	update(p);
}
node qry(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return dat[p];
	int mid = (lp + rp) >> 1;
	node tmp;
	if(l <= mid) tmp = qry(p<<1, lp, mid, l, r);
	if(r > mid) tmp = merge(tmp, qry(p<<1|1, mid + 1, rp, l, r));
	return tmp;
}

node getMin2(int u, int v) {
	node res;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		res = merge(res, qry(1, 1, n, dfn[top[u]], dfn[u]));
		u = fa[u];
	}
	if(dep[u] < dep[v]) swap(u, v);
	return merge(res, qry(1, 1, n, dfn[v],dfn[u]));
}

int main() {
	memset(head, -1, sizeof(head));
	int m, u, v, w, cnt = 0;
	ll ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		ed[i].u = u; ed[i].v = v;
	}
	sort(ed + 1, ed + n + 1, cmp1);
	for(int i = 1; i <= n; ++i) fat[i] = i;
	for(int i = 1; i <= m && cnt < n - 1; ++i) {
		if(find(ed[i].u) != find(ed[i].v)) {
			fat[fat[ed[i].u]] = fat[ed[i].v];
			++cnt; ed[i].intree = 1;
			addedge(ed[i].u, ed[i].v, ed[i].w);
			addedge(ed[i].v, ed[i].u, ed[i].w);
			ans += ed[i].w;
		} else ed[i].intree = 0;
	}
	dfs1(1, 0, 0);
	dfs2(1, 1);
	int change = inf;
	for(int i = 1; i <= m; ++i)
		if(!ed[i].intree) {
			node now = getMin2(ed[i].u, ed[i].v);
			if(ed[i].w == now.m1) {
				if(now.m2 != inf) change = min(ed[i].w - now.m2, change);
			}
			else if(now.m1 != inf) change = min(change, ed[i].w - now.m1);
		}
	ans += change;
	printf("%lld\n", ans);
	return 0;
}
