#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 123456, maxm = 345678, inf = 2147483647, p = 1000000007;
typedef long long ll;

int cost[maxn];
int head[maxn], ver[maxm], nex[maxm], tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;	
}

int dfn[maxn], low[maxn], minCost[maxn], co[maxn], num[maxn], sta[maxn], col = 1, dfs_clock = 1, top;
void tarjan(int cur) {
	dfn[cur] = low[cur] = dfs_clock++;
	sta[top++] = cur;
	for(int i = head[cur]; ~i; i = nex[i]) {
		if(!dfn[ver[i]]) {
			tarjan(ver[i]);
			low[cur] = min(low[cur], low[ver[i]]);	
		} else if(!co[ver[i]]) {
			low[cur] = min(low[cur], dfn[ver[i]]);
		}
	}
	if(dfn[cur] == low[cur]) {
		minCost[col] = cost[cur]; num[col] = 1;
		while(sta[--top] != cur) {
			co[sta[top]] = col;
			if(cost[sta[top]] < minCost[col]) {
				minCost[col] = cost[sta[top]];
				num[col] = 1;
			} else if(cost[sta[top]] == minCost[col]) {
				++num[col];	
			}
		}
		co[cur] = col++;
	}
}

int main() {
	memset(head, -1, sizeof(head));
	int n, m, u, v;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", cost + i);
	scanf("%d", &m);
	while(m--) {
		scanf("%d %d", &u, &v);
		addedge(u, v);
	}
	for(int i = 1; i <= n; ++i)
		if(!co[i])
			tarjan(i);
	ll ansCost = 0, ansNum = 1;
	for(int i = 1; i < col; ++i) {
		ansCost += minCost[i];
		ansNum = ansNum * num[i] % p;
	}
	printf("%lld %lld\n", ansCost, ansNum);
	return 0;
}
