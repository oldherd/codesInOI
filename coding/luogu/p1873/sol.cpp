#include <cstdio>
#include <queue>
#define pid pair<int, double>

using namespace std;

const int bs = 900<<20, maxm = 810, maxn = 1010, inf = 0x3f3f3f3f;

#define max(i, j) (i) > (j) ? (i) : (j);

inline char gc() {
	static char buf[bs], *p1 = buf, *p2 = buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,bs,stdin),p1==p2)?EOF:*p1++;
}

inline void read(int &x) {
	x = 0; char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x=(x<<3)+(x<<1)+(ch&15), ch = gc();
}

struct edges{
	int to, nex;
	double wei;
}e[maxn*maxn];
int head[maxn], tot;
inline void addedge(int u, int v, double w) {
	e[tot] = (edges){v, head[u], w}; head[u] = tot++;
}

priority_queue<pid> q;
int x[maxm], y[maxm];
double d[maxm];

inline void dij(int m) {
	d[m] = 0; q.push(make_pair(0, m));
	while(!q.empty()) {
		int cur = q.top().second; double dmen = -q.top().first; q.pop();
		if(dmen > d[cur]) continue;
		for(int i = head[cur]; i != -1; i = e[i].nex) {
			int u = cur, v = e[i].to; double w = e[i].wei;
			if(d[v] > max(d[u], w)) {
				d[v] = max(d[u], w);
				q.push(make_pair(-d[v], v));
			}
		}
	}
}

inline void edge_add() {
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			if(i != j)
				addedge(i, j, sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
	for(int i = 0; i < m; i++) {
		addedge(i, m, x[i]); addedge(m, i, x[i]);
		addedge(i, m+1, n-x[i]); addedge(m+1, i, n-x[i]);
	}
}

int main() {
	int n, m;
	read(n); read(m);
	for(int i = 0; i < m; i++) read(x[i], y[i]);
	for(int i = 1; i <= maxm; i++) d[i] = inf;
	edge_add();
	dij(m);
	printf("%.2f\n", d[m+1]);
	return 0;
}
