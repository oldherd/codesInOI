#include <cstdio>
#include <cstring>

using namespace std;

int n;

struct edges{
    int to, nex;
}edge[50010];
int head[10010], tot;

void addedge(int u, int v) {
    edge[tot] = (edges){v, head[u]}; head[u] = tot++;
}

int dfn[10010], low[10010], vis[10010], stk[10010], pbl[10010], amt[10010], sp = 0, dfs_clock = 1, blc = 0;
vector<int> v[10010];
void tarjan(int u) {
    dfn[u] = low[u] = dfs_clock++;
    vis[u] = 1; stk[sp++] = u;
    for(int i = head[u]; i != -1; i = e[i].nex) {
		if(!dfn[e[i].to]) {
		    tarjan(e[i].to);
		    low[u] = min(low[u], low[e[i].to]);
		} else {
		    low[u] = min(low[u], dfn[e[i].to]);
		}
    }
    if(dfn[u] == low[u]) {
		while(stk[sp] != u)
		    v[blo].push_back(stk[sp]), pbl[stk[sp--]] = blc, amt[blc]++;
		v[blc++].push_back(u);
		sp--; amt[blc]++;
    }
}

int out[10010], tt = 0, id;

int main() {
    int u, v;
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    while(m--) {
		scanf("%d %d", &u, &v);
		addedge(u, v);
    }
    for(int i = 1; i <= n; i++)
		if(!dfn[i]) {
			tarjan(i);
		}
	for(int i = 1; i <= n; i++) {
		for(int j = head[i]; j != -1; j = e[j].nex)
			if(pbl[e[j].to] != pbl[i]) {
				out[pbl[i]]++;	
			}
	}
	for(int i = 1; i <= n; i++)
		if(!out[i]) tt++, id = i;
	if(tt == 0 || tt == 2) 
    return 0;
}

