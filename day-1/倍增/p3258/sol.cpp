#include <cstdio>
#include <cstring>
#include <cmath>
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin),p1==p2)?EOF:*p1++)

using namespace std;

char buf[2000000], *p1 = buf, *p2 = buf;
int a[300010];
int d[300010], fa[300010][30], t;
int w[300010], ans[300010];

inline void read(int &x) {
	x = 0; char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch=gc(); 
}

struct Map{
	int head[300010], ver[600010], wei[600010], nex[600010], tot;
	Map() {
		memset(head, -1, sizeof(head));
		tot = 0;
	}
	inline void add(int u, int v) {
		ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
	}
};

Map g1;

void dfs(int pre, int cur) {
	d[cur] = d[pre] + 1; fa[cur][0] = pre;
	for(int i = 1; i <= t; i++) fa[cur][i] = fa[fa[cur][i-1]][i-1];
	for(int i = g1.head[cur]; i != -1; i = g1.nex[i]) if(g1.ver[i] != pre)
		dfs(cur, g1.ver[i]);
}

inline void swap(int &i, int &j) {
	int t = i; i = j; j = t;
}

inline int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	for(int i = t; i > -1; --i) if(d[fa[v][i]] >= d[u]) v = fa[v][i];
	if(u == v) return u;
	for(int i = t; i > -1; --i) if(fa[v][i] != fa[u][i]) v = fa[v][i], u = fa[u][i];
	return fa[u][0];
}

void dfsans(int cur) {
	ans[cur] += w[cur];
	for(int i = g1.head[cur]; i != -1; i = g1.nex[i]) if(g1.ver[i] != fa[i][0]){
		dfsans(g1.ver[i]);
		ans[cur] += w[g1.ver[i]];
	}
}

/*
void print(int n) {
	for(int i = 1; i <= n; i++) {
		for(int j = g1.head[i]; j != -1; j = g1.nex[j]) printf("(%d %d) ", i, g1.ver[j]);
		printf("\n");
	}
}*/

int main() {
	int n, u, v;
	read(n);
	t = (int)(log(n) / log(2)) + 1;
	for(int i = 1; i <= n; i++)	read(a[i]);
	for(int i = 1; i < n; i++) {
		read(u); read(v);
		g1.add(u, v);
	}
	//print(n);
	d[0] = 0;
	dfs(0, 1);
	for(int i = 2; i <= n; i++) {
		int anc = lca(a[i-1], a[i]);
		w[a[i-1]]++; 
		w[a[i]]++; 
		w[anc]--; 
		w[fa[anc][0]]--;
	}
	dfsans(1);
	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}
