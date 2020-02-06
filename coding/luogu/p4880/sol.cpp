#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

const int maxn = 100010, maxm = 1000010, maxt = 100010;

inline char gc() {
	static char buf[1<<21], *p1 = buf, *p2 = buf;
	return p1==p2 && (p2=(p1=buf)+fread(buf, 1, 1<<21, stdin), p1==p2) ? EOF : *p1++;
}

inline void read(int &x) {
	x = 0; char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}

struct chg{
	int time, pl;
	inline bool operator < (const chg & o) const {
		return time < o.time;
	}
}cg[maxt];

struct edges{
	int to, wei, nex;
}e[maxm<<1];
int head[maxn], tot;

inline void addedge(int u, int v, int w) {
	e[tot] = (edges){v, w, head[u]}; head[u] = tot++;
}


priority_queue<pii> q;
int d[maxn];
inline void dij(int s) {
	memset(d, -1, sizeof(d));
	d[s] = 0; q.push(make_pair(0, s));
	while(!q.empty()) {
		int cur = q.top().second, dmen = -q.top().first; q.pop();
		if(dmen > d[cur]) continue;
		for(int i = head[cur]; i != -1; i = e[i].nex) {
			if(d[e[i].to] == -1 || d[e[i].to] > d[cur] + e[i].wei) {
				d[e[i].to] = d[cur] + e[i].wei;
				q.push(make_pair(-d[e[i].to], e[i].to));
			}
		}
	}
}

int main() {
	//freopen("yl.in", "r", stdin); 
	memset(head, -1, sizeof(head));
	int n, m, b, e, u, v, w, t;
	read(n); read(m); read(b); read(e);
	while(m--) {
		read(u); read(v); read(w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	read(t);
	for(int i = 0; i < t; i++)
		read(cg[i].time), read(cg[i].pl);
	sort(cg, cg+t);
	dij(b);
	if(t == 0) {
		printf("%d\n", d[e]);
	} else if(d[e] < cg[0].time) {
		printf("%d\n", d[e]);
	} else {
		for(int i = 0; i < t; i++) {
			int pls = cg[i].pl, tm = i != t ? cg[i+1].time : 0x3f3f3f3f;
			if(d[pls] < tm) {
				printf("%d\n", max(cg[i].time, d[pls]));
				return 0;
			}
		}
	}
	return 0;
}
