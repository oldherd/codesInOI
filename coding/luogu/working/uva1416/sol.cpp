#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 110, maxm = 1010, down = (1<<30) - 2, inf = 0x3f3f3f3f;

int n, L;

int head[maxn], ver[maxm<<1], wei[maxm<<1], nex[maxm<<1], tot;
inline void addedge(int u, int v, int w) {
	ver[tot] = v; wei[tot] = w; nex[tot] = head[u]; head[u] = tot++;
}

struct dijer {
	int pl, dis;
	dijer(int P, int D) : pl(P), dis(D) {}
};
bool operator < (const dijer &a, const dijer &b) { return a.dis > b.dis; }

int dist[maxn][maxn], rdis[maxn][maxn], exi[maxn][maxm], p[maxn][maxn];
inline void dij(int s) {
	priority_queue<dijer> q;
	int *dis = dist[s];
	memset(dis, 0x3f, maxn*sizeof(int));
	dis[s] = 0; q.push(dijer(s, 0));
	while(!q.empty()) {
		int cur = q.top().pl, dmen = q.top().dis; q.pop();
		if(dmen > dis[cur]) continue;
		if(cur != s) exi[s][p[s][cur] & down] = 1;
		for(int i = head[cur]; i != -1; i = nex[i])
			if(dis[ver[i]] > dis[cur] + wei[i]) {
				dis[ver[i]] = dis[cur] + wei[i];
				p[s][ver[i]] = i;
				q.push(dijer(ver[i], dis[ver[i]]));
			}
	}
}

inline void redij(int s, int id) {
	priority_queue<dijer> q;
	int *dis = rdis[s];
	memset(dis, 0x3f, sizeof(int)*maxn);
	dis[s] = 0; q.push(dijer(s, 0));
	while(!q.empty()) {
		int cur = q.top().pl, dmen = q.top().dis; q.pop();
		if(dmen > dis[cur]) continue;
		for(int i = head[cur]; i != -1; i = nex[i])
			if((dis[ver[i]] > dis[cur] + wei[i]) && ((i & down) != id)) {
				dis[ver[i]] = dis[cur] + wei[i];
				q.push(dijer(ver[i], dis[ver[i]]));
			}
	}
}

int main() {
	int m, ui, vi, wi;
	scanf("%d %d %d", &n, &m, &L);
	memset(head, -1, sizeof(head));
	memset(p, -1, sizeof(p));
	while(m--) {
		scanf("%d %d %d", &ui, &vi, &wi);
		addedge(ui, vi, wi);
		addedge(vi, ui, wi);
	}
	for(int i = 1; i <= n; i++) 
		dij(i);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans += dist[i][j] == inf ? L : dist[i][j];
	printf("%d ", ans);
	for(int i = 0; i < tot; i += 2) {
		int tmpans = 0;
		for(int j = 1; j <= n; j++) {
			if(exi[j][i]) {
				redij(j, i);
				for(int k = 1; k <= n; k++)
					tmpans += rdis[j][k] == inf ? 1000 : rdis[j][k];
			} else {
				for(int k = 1; k <= n; k++)
					tmpans += dist[j][k] == inf ? 1000 : dist[j][k];
			}
		}
		ans = max(ans, tmpans);
	}
	printf("%d\n", ans);
	return 0;
}
