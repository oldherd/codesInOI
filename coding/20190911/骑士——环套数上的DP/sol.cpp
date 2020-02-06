#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1000010;
int head[maxn], ver[maxn<<1], nex[maxn<<1], wt[maxn], f[maxn][2], tot, se1, se2, ban;
bool vis[maxn];
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

void dfs(int epre, int cur) {
	for(int i = head[cur]; i != -1; i = nex[i])
		if((i^1) != epre) {
			if(vis[ver[i]]) {
				se1 = cur; se2 = ver[i]; ban = i;
				continue;
			}
			dfs(i, ver[i]);
		}
}

void dp(int epre, int cur) {
	f[cur][0] = 0; f[cur][1] = wt[cur];
	for(int i = head[cur]; i != -1; i = nex[i])
		if((i^1) != epre && i != ban && i != (ban^1)) {
			dp(i, ver[i]);
			f[cur][0] += max(f[ver[i]][0], f[ver[i]][1]);
			f[cur][1] += f[ver[i]][0];
		}
}

int main() {
	ios::sync_with_stdio(false);
	memset(head, -1, sizeof(head));
	int n, v, ans, tans;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> wt[i] >> v;
		addedge(i, v); addedge(v, i);
	}
	for(int i = 1; i <= n; i++)
		if(!vis[i]) {
			vis[i] = true;
			dfs(-1, 1);
			dp(-1, se1); tans = f[se1][0];
			wt[se2] = 0; dp(-1, se1);
			ans += max(f[se1][0], max(f[se1][1], tans));
		}
	cout << ans << endl;
	return 0;
}
