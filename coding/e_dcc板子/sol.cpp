#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1010, maxm = 1010;
#define min(x, y) (x) < (y) ? (x) : (y)

int head[maxn], ver[maxm<<1], nex[maxm<<1], tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

int dfn[maxn], low[maxn], bri[maxn], dfs_clock = 1;
inline void tarjan(int cur, int in_edge) {		//edge
	dfn[cur] = low[cur] = dfs_clock++;
	for(int i = head[cur]; i != -1; i = nex[i]) {
		if(!dfn[ver[i]]) {
			tarjan(ver[i], i);
			low[cur] = min(low[cur], low[ver[i]]);
			if(dfn[cur] < low[ver[i]])
				bri[i] = bri[i^1] = 1;
		} else if((i^1) != in_edge){
			low[cur] = min(dfn[ver[i]], low[cur]);
		}
	}
}

int c[maxn], dcc;
inline void dfs_c(int cur) {
	c[cur] = dcc;
	for(int i = head[cur]; i != -1; i = nex[i])
		if(!c[ver[i]] && !bri[i])
			dfs_c(ver[i]);
}

int hc[maxn], vc[maxm<<1], nc[maxn], tt;
inline void addc(int u, int v) {
	vc[tt] = v; nc[tt] = hc[u]; hc[u] = tt++;
}

bool vis[maxn];
inline int dfs(int cur) {
	int ans = 0;
	vis[cur] = true;
	for(int i = head[cur]; i != -1; i = nex[i])
		if(!vis[ver[i]]) {
			ans += dfs(ver[i]);
		}
	return ans == 0 ? 1 : ans;;
}

namespace db{
    void ptree(int n) {
        for(int i = 1; i <= n; i++) {
            for(int j = head[i]; j != -1; j = nex[j]) {
                printf("(%d %d) ", i, ver[j]);
            }
            printf("\n");
        }
    }
    void pblo(int n) {
        for(int i = 1; i <= n; i++) {
            printf("(%d %d)", i, c[i]);
        }
        printf("\n");
    }
    void pbri() {
        for(int i = 0; i < tot; i+=2)
            if(bri[i]) {
                printf("(%d %d)", ver[i], ver[i^1]);
            }
        printf("\n");
    }
    void pc(int n) {
    	for(int i = 1; i <= dcc; i++) {
    		for(int j = hc[i]; j != -1; j = nc[j])
    			printf("(%d %d)", i, vc[i]);
    		printf("\n");
		}
	}
}

int main() {
	int n, r, u, v;
	scanf("%d %d", &n, &r);
	memset(head, -1, sizeof(head));
	while(r--) {
		scanf("%d %d", &u, &v);
		addedge(u, v); addedge(v, u);
	}
	tarjan(1, maxm<<2);
	for(int i = 1; i <= n; i++)
		if(!c[i]) {
			dcc++;
			dfs_c(i);
		}
	memset(hc, -1, sizeof(hc));
	for(int i = 0; i < tot; i++)
		if(c[ver[i]] != c[ver[i^1]]) {
			addc(c[ver[i]], c[ver[i^1]]);
			addc(c[ver[i^1]], c[ver[i]]);
		}
	return 0;
}
