#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 50010, maxm = 50010;
#define min(x, y) (x) < (y) ? (x) : (y)

int head[maxn], ver[maxm<<1], nex[maxm<<1], tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

vector<int> dcc[maxn];
int dfn[maxn], low[maxn], cut[maxn], stack[maxn], st, root, dfs_clock = 1, cc;
inline void tarjan(int cur) {
	stack[st++] = cur;
	dfn[cur] = low[cur] = dfs_clock++;
	if(cur == root && head[cur] == -1) {
		dcc[cc++].push_back(cur);
		return;
	}
	int flag = 0;
	for(int i = head[cur]; i != -1; i = nex[i]) {
		if(!dfn[ver[i]]) {
			tarjan(ver[i]);
			low[cur] = min(low[cur], low[ver[i]]);
			if(dfn[cur] <= low[ver[i]]) {
				flag++;
				if(cur != root || flag == 2) cut[cur] = 1;
				int t;
				do {
					t = stack[(st--)-1];
					dcc[cc].push_back(t);
				}while(t != ver[i]);
				dcc[cc++].push_back(cur);
			}
		} else 
			low[cur] = min(low[cur], dfn[ver[i]]);
	}
}



int main() {
	int n, m, u, v, cases = 1;
	while(scanf("%d", &m) == 1 && m) {
		memset(head, -1, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
		memset(cut, 0, sizeof(cut)); 
		n = cc = tot = 0;
		while(m--) {
			scanf("%d %d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		n = max(n, u); n = max(n, v);
		for(int i = 1; i <= n; i++)
			if(!dfn[i]) {
				st = 0;
				root = i, tarjan(i);
			}
		if(cc == 1) {
			printf("Case %d: %d %lld\n", cases++, 2, (long long)dcc[0].size() * (dcc[0].size()-1) / 2);
			dcc[0].clear();
			continue;
		}
		long long num = 0, sor = 1;
		for(int i = 0; i < cc; i++) {
			int ncut = 0;
			for(vector<int>::iterator it = dcc[i].begin(); it != dcc[i].end(); it++)
				if(cut[*it]) ncut++;
			if(ncut == 1) {
				num++; sor *= (dcc[i].size()-ncut);
			}
			dcc[i].clear();
		}
		printf("Case %d: %lld %lld\n", cases++, num, sor);
	}	return 0;

}
