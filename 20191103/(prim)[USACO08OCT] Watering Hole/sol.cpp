#include <cstdio>

using namespace std;

const int N = 345, INF = 0x3f3f3f3f;
int d[N][N], dis[N], vis[N], ans = 0;
inline int min(int x, int y) { return x < y ? x : y; }

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", dis + i);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &d[i][j]);
	int cur = 0; dis[cur] = INF;
	for(int i = 1; i <= n; ++i) if(dis[i] < dis[cur]) cur = i;
	ans += dis[cur]; vis[cur] = 1;
	for(int i = 1; i <= n; ++i) if(!vis[i]) dis[i] = min(dis[i], d[cur][i]);
	for(int i = 1; i < n; ++i) {
		cur = 0;
		for(int i = 1; i <= n; ++i) if(!vis[i] && dis[i] < dis[cur]) cur = i;
		vis[cur] = 1; ans += dis[cur];
		for(int i = 1; i <= n; ++i) if(!vis[i]) dis[i] = min(dis[i], d[cur][i]); 
	}
	printf("%d\n", ans);
	return 0;
}
