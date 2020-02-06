#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

const int maxn = 2000010, md = 998244353;
int head[maxn], ver[maxn<<1], pre[maxn<<1], nex[maxn<<1], tot, n;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u];
	if(head[u] != -1) pre[head[u]] = tot;
	pre[tot] = -1; head[u] = tot++;
}

int a[maxn], rk[maxn];
bool vis[maxn];

bool cmp(int x, int y) { return a[x] < a[y]; }

inline void link(int u, int v) {
	for(int i = head[v], t = nex[i]; i != -1; i = t, t = nex[i])
		if(ver[i] != u) {
			nex[ver[i]] = head[u]; pre[ver[i]] = -1;
			nex[i] = head[u];
			if(head[u] != -1) pre[head[u]] = i;
			head[u] = i;
			ver[i^1] = u;
		}
}

void printT() {
	for(int i = 1; i <= n; i++) {
		cout << i << ": ";
		for(int j = head[i]; j != -1; j = nex[j]) cout << ver[j] << " ";
		cout << endl;
	}
} 

ull merge(int cur) {
	if(vis[cur]) return 0;
	ull ans = 0;
	bool flag = true;
	while(flag) {
		flag = false;
		for(int i = head[cur]; i != -1; i = nex[i]) {
			if(vis[ver[i]]) {
				nex[pre[ver[i]]] = nex[ver[i]];
				pre[nex[ver[i]]] = pre[ver[i]];
				continue;
			}
			if(a[ver[i]] <= a[cur]) {
				ans = (ans + a[cur]) % md;
				vis[ver[i]] = true;
				link(cur, ver[i]);
				if(pre[i] != -1) nex[pre[i]] = nex[i];
				else head[cur] = nex[i];
				pre[nex[i]] = pre[i];
				flag = true;
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	memset(head, -1, sizeof(head));
	memset(pre, -1, sizeof(pre));
	ull ans = 0;
	int u, v;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], rk[i] = i;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		addedge(u, v); addedge(v, u);
	}
	sort(rk+1, rk+n+1, cmp);
	for(int i = 1; i <= n; i++) ans = (ans + merge(rk[i])) % md;
	cout << ans << endl;
	return 0;	
}
