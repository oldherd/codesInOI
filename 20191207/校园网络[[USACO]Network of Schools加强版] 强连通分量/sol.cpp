#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 12345, M = 5678901;

int head[N], ver[M], nex[M], my[M], tot, n;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; my[tot] = u; head[u] = tot++;
}

int sta[N], dfn[N], low[N], co[N], top, col = 1, dfs_clock = 1;
void tarjan(int cur) {
	dfn[cur] = low[cur] = dfs_clock++;
	sta[top++] = cur;
	for(int i = head[cur]; ~i; i = nex[i])
	if(!dfn[ver[i]]) {
		tarjan(ver[i]);
		low[cur] = min(low[cur], low[ver[i]]);
	} else if(!co[ver[i]]) {
		low[cur] = min(low[cur], dfn[ver[i]]);
	}
	if(dfn[cur] == low[cur]) {
		while(sta[--top] != cur)
			co[sta[top]] = col;
		co[cur] = col++;
	}
}

int ind[N], outd[N];

int main() {
	memset(head, -1, sizeof(head));
	int tmp;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		while(~scanf("%d", &tmp) && tmp)
			addedge(i, tmp);
	}
	for(int i = 1; i <= n; ++i) if(!co[i]) tarjan(i);
	for(int i = 0; i < tot; ++i) {
		if(co[my[i]] != co[ver[i]]) {
			++ind[co[ver[i]]]; ++outd[co[my[i]]];
		}
	}
	int id0 = 0, od0 = 0;
	for(int i = 1; i < col; ++i) {
		if(!ind[i]) ++id0;
		if(!outd[i]) ++od0;  
	}
	if(col == 2) {
		printf("1\n0\n");
	} else {
		printf("%d\n%d\n", id0, max(id0, od0));
	}
	return 0;
}
