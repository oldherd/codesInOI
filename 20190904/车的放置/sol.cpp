#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 210, me = maxn*maxn;
int a[maxn][maxn];
int mfa[maxn];
bool vis[maxn];

int head[maxn], ver[me], nex[me], tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

bool dfs(int cur) {
	for(int i = head[cur]; i != -1; i = nex[i])
		if(!vis[ver[i]]) {
			vis[ver[i]] = true;
			if(!mfa[ver[i]] || dfs(mfa[ver[i]])) {
				mfa[ver[i]] = cur;
				return true;	
			}
		}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	memset(head, -1, sizeof(head));
	int n, m, t, tx, ty;
	cin >> n >> m >> t;
	while(t--) {
		cin >> tx >> ty;
		a[tx][ty] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(!a[i][j])
				addedge(i, j);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if(dfs(i)) ans++;
	}
	cout << ans << endl;
	return 0;
}
