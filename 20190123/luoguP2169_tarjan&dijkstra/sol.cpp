#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;

const int maxn = 234567, maxm = 1234567;
ll inf = 9000000000000000;
int head[maxn << 1], ver[maxm << 1], wei[maxm << 1], nex[maxm << 1], my[maxm << 1], n, tot;

inline void addedge(int u, int v, int w) {
	ver[tot] = v; wei[tot] = w; my[tot] = u; nex[tot] = head[u]; head[u] = tot++;
}

int co[maxn], dfn[maxn], low[maxn], sta[maxn], top, col = 1, dfs_clock = 1;
inline void tarjan(int cur) {
	dfn[cur] = low[cur] = dfs_clock++;
	sta[top++] = cur;
	for(int i = head[cur]; ~i; i = nex[i])
		if(!dfn[ver[i]]) {
			tarjan(ver[i]);
			low[cur] = min(low[cur], low[ver[i]]);
		} else if(!co[ver[i]]) {
			low[cur] = min(low[cur], dfn[ver[i]]);
		}
	if(dfn[cur] == low[cur]) {
		while(sta[--top] != cur) {
			co[sta[top]] = col;
		}
		co[cur] = col++;
	}
}

struct nodeq {
	int x;
	ll dis;
	nodeq(int X, ll DIS) : x(X), dis(DIS) {}
	bool operator > (const nodeq& o) const { return dis > o.dis; }
};
priority_queue< nodeq, vector<nodeq>, greater<nodeq> > q;
ll dis[maxn];
void dijkstra(int s) {
	for(int i = 1; i <= col; ++i) dis[i] = inf;
	dis[s] = 0; q.push(nodeq(s, 0));
	while(!q.empty()) {
		nodeq cur = q.top(); q.pop();
		if(dis[cur.x] < cur.dis) continue;
		for(int i = head[cur.x + n]; ~i; i = nex[i]) {
			if(dis[ver[i]] > dis[cur.x] + wei[i]) {
				dis[ver[i]] = dis[cur.x] + wei[i];
				q.push(nodeq(ver[i], dis[ver[i]]));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head, -1, sizeof(head));
	int m, u, v, w;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		addedge(u, v, w);
	}
	for(int i = 1; i <= n; ++i)
		if(!co[i])
			tarjan(i);
//	for(int i = 1; i <= n; ++i) cout << co[i] << ' ';
//	cout << '\n';
	int tt = tot;
	for(int i = 0; i < tt; ++i) {
		if(co[ver[i]] != co[my[i]]) {
			addedge(co[my[i]] + n, co[ver[i]], wei[i]);
			//cout << co[my[i]] << ' ' << co[ver[i]] << ' ' << wei[i] << '\n';
		}
	}
	int st = co[1], ed = co[n];
	dijkstra(st);
	cout << dis[ed] << endl;
	return 0;
}
