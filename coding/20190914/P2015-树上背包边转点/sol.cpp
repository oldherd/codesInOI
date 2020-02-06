#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 110;
int head[maxn], ver[maxn<<1], nex[maxn<<1], wei[maxn<<1], f[maxn][maxn], tot, q;
inline void addedge(int u, int v, int w) {
	ver[tot] = v; wei[tot] = w; nex[tot] = head[u]; head[u] = tot++;	
}

void dfs(int epre, int cur) {
	for(int i = head[cur]; i != -1; i = nex[i])
		if((i^1) != epre) {
			dfs(i, ver[i]);
			for(int j = q; j > 0; --j)
				for(int k = 0; k < j; k++)
					f[cur][j] = max(f[cur][j], f[cur][j-k-1]+f[ver[i]][k]+wei[i]);
		}
}

int main() {
	ios::sync_with_stdio(false);
	memset(head, -1, sizeof(head)); 
	int n, u, v, w;
	cin >> n >> q;
	for(int i = 1; i < n; i++) {
		cin >> u >> v >> w;
		addedge(u, v, w); addedge(v, u, w);
	}
	dfs(-1, 1);
	cout << f[1][q] << endl;
	return 0;
}

//边转点,每个结点记录的是该节点为根的子树的选择信息,向上转移时强制加入它与父亲节点的连边 
