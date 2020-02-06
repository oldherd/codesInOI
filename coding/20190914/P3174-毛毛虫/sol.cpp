#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 300010; 
int head[maxn], ver[maxn<<1], nex[maxn<<1], f[maxn], tot, ans;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;	
}

void dfs(int epre, int cur) {
	int m1 = -1, m2 = -1, cnt = 0;
	for(int i = head[cur]; i != -1; i = nex[i])
		if((i^1) != epre) {
			dfs(i, ver[i]); cnt++;
			if(f[ver[i]] > m1) m2 = m1, m1 = f[ver[i]];
			else m2 = max(f[ver[i]], m2);
		}
	if(m1 != -1) f[cur] = m1 + cnt;
	else f[cur] = 1;
	ans = max(1+(m1==-1?0:m1)+(m2==-1?0:m2)+(cur==1?0:1)+(cnt>2?cnt-2:0), ans);
}

int main() {
	ios::sync_with_stdio(false);
	memset(head, -1, sizeof(head));
	int n, m, u, v;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v;
		addedge(u, v); addedge(v, u);
	}
	dfs(-1, 1);
	cout << ans << endl;
	return 0;	
}

//$f_cur$定义为从cur子树中的叶节点到cur的直线路径中最大的在该路径上或直接与该路径相连的节点的点数之和的最大值。在更新答案时考虑用跨过cur的路径更新(如果cur存在两个以上的孩子节点的话).使用f值最大的两个孩子更新路径。若只有一个孩子则直接用这个孩子加上节点cur更新答案。计算答案的时候注意一些即可。 
