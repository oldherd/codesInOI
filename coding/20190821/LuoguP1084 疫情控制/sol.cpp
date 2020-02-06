#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

const long long lf = 100000000000000000;
const int sz = 1<<20, maxn = 50010, maxt = 20;
//IO & tool
char buf[sz], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,sz,stdin),p1==p2)?EOF:*p1++; }
inline void read(int &x) {
	x = 0; char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x=(x<<3)+(x<<1)+(ch&15), ch = gc();
}
//Graphs
int troop[maxn], n, k;
int head[maxn], ver[maxn<<1], wei[maxn<<1], nex[maxn<<1], tot;
long long cost[maxn][maxt];
int fa[maxn][maxt], sup[maxn];
inline void addedge(int u, int v, int w) {
	ver[tot] = v; wei[tot] = w; nex[tot] = head[u]; head[u] = tot++;
}

inline void dfs(int pre, int cur, int w, int supp) {
	fa[cur][0] = pre; cost[cur][0] = w; sup[cur] = supp;
	for(int i = 1; i < maxt; i++) {
		fa[cur][i] = fa[fa[cur][i-1]][i-1];
		cost[cur][i] = cost[cur][i-1] + cost[fa[cur][i-1]][i-1];
	}
	for(int i = head[cur]; i != -1; i = nex[i])
		if(ver[i] != pre)
			dfs(cur, ver[i], wei[i], supp);
}

inline void mis() {
	fa[1][0] = 1; cost[1][0] = 0;
	for(int i = 1; i < maxt; i++) fa[1][i] = 1, cost[1][i] = 0;
	for(int i = head[1]; i != -1; i = nex[i])
		dfs(1, ver[i], wei[i], ver[i]);
}

inline int getanc(int cur, long long t) {
	for(int i = maxt-1; i > -1 && t; --i)
		if(cost[cur][i] <= t) {
			cur = fa[cur][i];
			t -= cost[cur][i];
		}
	return cur;
}

bool col[maxn];
long long mlft[maxn];
multiset<long long> s;
inline bool dfss(int pre, int cur) {
	bool flag = false;
	for(int i = head[cur]; i != -1; i = nex[i])
		if(ver[i] != pre) {
			flag = true;
			if(!col[ver[i]])
				if(!dfss(cur, ver[i]))
					return false;
		}
	return flag;
}

inline bool calc(long long t) {
	s.clear();
	s.insert(-lf); s.insert(lf);
	memset(col, 0, sizeof(col));
	memset(mlft, -1, sizeof(mlft));
	for(int i = 0; i < k; i++) {
		int tp = troop[i];
		if(tp == 1) { s.insert(t); continue; }
		int p = getanc(tp, t);
		if(p == 1) {
			long long lft = t - cost[tp][maxt-1];
			if(mlft[sup[tp]] == -1 || mlft[sup[tp]] > lft) mlft[sup[tp]] = lft;
			s.insert(lft);
		} else {
			col[p] = true;
		}
	}
	for(int i = head[1]; i != -1; i = nex[i])
		if(!col[ver[i]]) {
			if(dfss(fa[ver[i]][0], ver[i])) continue;
			int cs = mlft[ver[i]] == -1 ? cost[ver[i]][0] : min(mlft[ver[i]], cost[ver[i]][0]);
			if(s.size() == 2) return false;
			set<long long>::iterator it = s.lower_bound(cs);
			if((*it) == lf) return false;
			s.erase(it);
		}
	
	return true;
}

int main() {
	memset(head, -1, sizeof(head));
	long long l = 0, r = 0;
	int u, v, w;
	read(n);
	for(int i = 1; i < n; i++) {
		read(u); read(v); read(w);
		addedge(u, v, w);
		addedge(v, u, w);
		r = max(r, (long long)w);
	}
	mis();
	read(k);
	for(int i = 0; i < k; i++) read(troop[i]);
	r *= k;
	while(l < r) {
		long long mid = (l + r) >> 1;
		if(calc(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", l==0&&!calc(0)?-1:l);
	return 0;
}
