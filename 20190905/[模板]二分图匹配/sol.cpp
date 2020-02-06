#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1010, maxm = maxn*maxn;

int head[maxn], ver[maxm], nex[maxm], tot;
int mfa[maxn];
bool vis[maxn]; 

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
	int n, m, e, u, v, ans = 0;
	cin >> n >> m >> e;
	for(int i = 1; i <= e; i++) {
		cin >> u >> v;
		if(u <= n && v <= m) addedge(u, v);
	}
	for(int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if(dfs(i)) ans++;
	}
	cout << ans << endl;
	return 0;	
}
