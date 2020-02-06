#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 50010;
const int inf = 0x3f3f3f3f;

int n, idn[maxn], ids[maxn];

inline int min(int x, int y) {
	return x < y ? x : y;
}

inline void swap(int &x, int &y) {
	int t = x; x = y; y = t;
}

#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin), p1==p2)?EOF:*p1++)
char buf[2000000], *p1 = buf, *p2 = buf;
inline void read(int &x) {
    x = 0;
    char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}

struct edge{
    int to, nex, id;
}e[maxn<<1];
int head[maxn], tot = 0;
inline void addedge(int u, int v, int _id) {
    e[tot] = (edge){v, head[u], _id}; head[u] = tot++;
    e[tot] = (edge){u, head[v], _id}; head[v] = tot++;
}

int fa[maxn], d[maxn], son[maxn], size[maxn], top[maxn], dfn[maxn], rk[maxn], dfs_clock = 1;
void dfs1(int pre, int cur) {
    fa[cur] = pre; d[cur] = d[pre]+1; size[cur] = 1;
    for(int i = head[cur]; i != -1; i = e[i].nex)
        if(e[i].to != pre) {
            dfs1(cur, e[i].to);
            size[cur] += size[e[i].to];
            if(size[e[i].to] > size[son[cur]]) son[cur] = e[i].to;
			idn[e[i].to] = e[i].id;
        }
}

void dfs2(int tp, int cur) {
    rk[dfs_clock] = cur; top[cur] = tp; dfn[cur] = dfs_clock++;
    if(!son[cur]) return;
    dfs2(tp, son[cur]);
    for(int i = head[cur]; i != -1; i = e[i].nex)
        if(!dfn[e[i].to])
            dfs2(e[i].to, e[i].to);
}

struct seg{
    int l, r, dat, laz;
}t[maxn<<4];

inline void build(int p, int l, int r) {
    t[p].l = l; t[p].r = r; t[p].dat = t[p].laz = inf;
    if(l == r) return;
    int mid = (l+r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
}

inline void pushdown(int p) {
	t[p<<1].dat = min(t[p<<1].dat, t[p].laz);
	t[p<<1|1].dat = min(t[p<<1|1].dat, t[p].laz);
	t[p<<1].laz = min(t[p<<1].laz, t[p].laz);
	t[p<<1|1].laz = min(t[p<<1|1].laz, t[p].laz);
	t[p].laz = inf;
}

inline void change(int p, int l, int r, int v) {
	if(l <= t[p].l && t[p].r <= r) {
		t[p].dat = min(t[p].dat, v);
		t[p].laz = min(t[p].laz, v);
		return;
	}
	if(t[p].laz != inf) pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(l <= mid) change(p<<1, l, r, v);
	if(r > mid) change(p<<1|1, l, r, v);
	t[p].dat = min(t[p<<1].dat, t[p<<1|1].dat);
}

inline int query(int p, int l, int r) {
	if(l <= t[p].l && t[p].r <= r)
		return t[p].dat;
	if(t[p].laz != inf) pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1, res = inf;
	if(l <= mid) res = min(res, query(p<<1, l, r));
	if(r > mid) res = min(res, query(p<<1|1, l, r));
	return res;
}

inline void cg(int x, int y, int v) {
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]]) swap(x, y);
		change(1, dfn[top[x]], dfn[x], v);
		x = fa[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
	change(1, dfn[y]+1, dfn[x], v);
}

namespace db {
	void tree() {
		for(int i = 1; i <= n; i++) {
			for(int j = head[i]; j != -1; j = e[j].nex)
				printf("(%d %d) ", i, e[j].to);
			printf("\n");
		}
	}
	void cut() {
		for(int i = 1; i <= n; i++) printf("(%d %d) ", dfn[i], top[i]);
		printf("\n");
	}
	void segtree(int d) {
		int l = 1, r = 2;
		while(d--) {
			for(int i = l; i != r; i++) {
				printf("(%d %d ", t[i].l, t[i].r);
				if(t[i].dat == inf) printf("inf ");
				else printf("%d ", t[i].dat);
				if(t[i].laz == inf) printf("inf) ");
				else printf("%d) ", t[i].laz);
			}
			printf("\n");
			l = r; r <<= 1;
		}
	}
}

int main() {
    int m, u, v, w;
    read(n); read(m);
    memset(head, -1, sizeof(head));
    for(int i = 1; i < n; i++) {
        read(u); read(v);
        addedge(u, v, i);
    }
    dfs1(0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    while(m--) {
		read(u); read(v); read(w);
		cg(u, v, w);
    }
	for(int i = 2; i <= n; i++) ids[idn[i]] = i;
	for(int i = 1; i < n; i++) {
		int t = query(1, dfn[ids[i]], dfn[ids[i]]);
		printf("%d\n", t==inf ? -1 : t);
	}
    return 0;
}