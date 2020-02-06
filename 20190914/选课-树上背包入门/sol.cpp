#include <iostream>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f, maxn = 310;
int head[maxn], ver[maxn<<1], nex[maxn<<1], w[maxn], f[maxn][maxn], tot, m;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;	
}

void dfs(int epre, int cur) {
	f[cur][1] = w[cur];
	for(int i = head[cur]; i != -1; i = nex[i])
		if((i^1) != epre) {
			dfs(i, ver[i]);
			for(int j = m+1; j > 0; --j)
				for(int k = 0; k <= j; k++)
					f[cur][j] = max(f[cur][j], f[cur][j-k]+f[ver[i]][k]);
		}
	f[cur][0] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	memset(head, -1, sizeof(head));
	memset(f, -inf, sizeof(f));
	int n, v;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> v >> w[i];
		addedge(i, v); addedge(v, i);
	}
	dfs(-1, 0);
	cout << f[0][m+1] << endl;
	return 0;
}

//树上背包,又称树形依赖背包,对每一个节点开一个背包,dfs时逆序扫一遍添加物品即可.
//细节的处理策略:我的解法是将初始值设为-inf,将该点的权重放到选1门课作为初始化,在背包结束的时候将0赋值为0表示不选该子树。  
//lyd书上的做法是先不管,f的初始值均为0,然后在最后强制选根的物品(f[cur][i] = f[cur][i-1] + w[i]).
