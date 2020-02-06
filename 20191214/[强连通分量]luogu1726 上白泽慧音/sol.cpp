#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5678, M = 56789;

int head[N], ver[M<<1], nex[M<<1], tot;
inline void addedge(int u, int v) {
    ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

int dfn[N], low[N], dfs_clock = 1;
int sta[N], top = 0;
int co[N], num[N], mini[N], col = 1;
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
		co[cur] = col;
		++num[col]; mini[col] = cur;
        while(sta[--top] != cur) {
			co[sta[top]] = col;
			++num[col];
			mini[col] = min(mini[col], sta[top]);
		}
		++col;
    }
}

int main() {
	memset(head, -1, sizeof(head));
    int n, m, u, v, type;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &type);
        addedge(u, v);
        if(type == 2) addedge(v, u);
    }
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
	int ans = 1;
	for(int i = 2; i < col; ++i) {
		if(num[ans] < num[i] || num[ans] == num[i] && mini[ans] > mini[i]) ans = i;
	}
	printf("%d\n", num[ans]);
	for(int i = 1; i <= n; ++i) if(co[i] == ans) printf("%d ", i);
	printf("\n");
    return 0;
}
