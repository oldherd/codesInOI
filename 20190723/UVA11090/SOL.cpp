#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const double exp = 1e-5;
const int maxn = 60, maxm = 2510;
int n;

int head[maxn], ver[maxm<<1], wei[maxm<<1], nex[maxm<<1], a[maxn][maxn], tot;
inline void addedge(int u, int v, int w) {
	ver[tot] = v; wei[tot] = w; nex[tot] = head[u]; head[u] = tot++;
}

double dis[maxn];
int inq[maxn], cnt[maxn];

inline bool ng_circle(double dx) {
	queue<int> q;
	memset(inq, 1, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++) {
		dis[i] = 0; q.push(i);
	}
	while(!q.empty()) {
		int cur = q.front(); q.pop(); inq[cur] = 0;
		for(int i = head[cur]; i != -1; i = nex[i])
			if(dis[ver[i]] > dis[cur] + wei[i] - dx) {
				dis[ver[i]] = dis[cur] + wei[i] - dx;
				if(!inq[ver[i]]) {
					if(++cnt[ver[i]] > n) return true;
					inq[ver[i]] = 1;
					q.push(ver[i]);
				}
			}
	}
	return false;
}

int main() {
	int T, m, u, v, w, cnt, mx;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		memset(head, -1, sizeof(head));
		memset(a, -1, sizeof(a));
		tot = 0;
		scanf("%d %d", &n, &m);
		while(m--) {
			scanf("%d %d %d", &u, &v, &w);
			a[u][v] = a[u][v] == -1 ? w : min(a[u][v], w);
			mx = max(a[u][v], mx);
		}
		for(int i = 1; i <= n; i++) { 
			addedge(0, i, 0);
			for(int j = 1; j <= n; j++)
				if(a[i][j] != -1) {
					addedge(i, j, a[i][j]);
					cnt++;
				}
		} 
		if(cnt < n || !ng_circle(mx+1)) {
			printf("Case #%d: No cycle found.\n", t);
			continue;
		}
		double l = 0, r = mx;
		while(r - l >= exp) {
			double mid = (l + r) / 2;
			if(ng_circle(mid)) r = mid;
			else l = mid;
		}
		printf("Case #%d: %.2f\n", t, l);
	}
	return 0;	
}
