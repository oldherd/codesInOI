#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 12345, M = 234567, INF = 0x3f3f3f3f;
int head[N<<1], ver[M<<1], nex[M<<1], tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

int vis[N];
void dfs(int cur) {
	for(int i = head[cur + N]; ~i; i = nex[i])
		if(!vis[ver[i]]) {
			vis[ver[i]] = 1;
			dfs(ver[i]);
		}
}

queue<int> q;
int dep[N], ena[N];
inline int bfs(int s, int t) {
	dep[s] = 0;
	q.push(s);
	if(!ena[s]) return -1;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int i = head[cur]; ~i; i = nex[i])
			if(ena[ver[i]] && !dep[ver[i]]) {
				if(ver[i] == t) return dep[cur] + 1;
				q.push(ver[i]);
				dep[ver[i]] = dep[cur] + 1;
			}
	}
	return -1;
}

int main() {
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis)); 
	int n, m, u, v, s, t, flg;
	scanf("%d %d", &n, &m);	
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		addedge(u, v);
		addedge(v + N, u);
	}
	scanf("%d %d", &s, &t);
	vis[t] = 1;	
	dfs(t);
	for(int i = 1; i <= n; ++i) {
		flg = vis[i];
		for(int j = head[i]; ~j && flg; j = nex[j]) 
			flg &= vis[ver[j]];
		ena[i] = flg;
	}
	printf("%d\n", bfs(s, t));
	return 0;
}
