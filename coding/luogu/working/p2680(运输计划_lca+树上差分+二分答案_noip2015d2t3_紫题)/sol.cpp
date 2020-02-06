#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 300010, maxm = 300010;
#define max(x, y) (x) > (y) ? (x) : (y)
inline void swap(int &x, int &y) {
    int t = x; x = y; y = t;
}

int s[maxm], e[maxm], lc[maxm], d[maxm], n, m;

int head[maxn], ver[maxn<<1], wei[maxn<<1], nex[maxn<<1], tot;
inline void addedge(int u, int v, int w) {
    ver[tot] = v; nex[tot] = head[u]; wei[tot] = w; head[u] = tot++;
}

const int maxp = 25;
int fa[maxn][maxp+10], dis[maxn], dep[maxn];
inline void dfs(int pre, int cur) {
    dep[cur] = dep[pre] + 1; fa[cur][0] = pre;
    for(int i = 1; i <= maxp; i++) fa[cur][i] = fa[fa[cur][i-1]][i-1];
    for(int i = head[cur]; i != -1; i = nex[i]) if(ver[i] != pre) {
        dis[ver[i]] = dis[cur] + wei[i];
        dfs(cur, ver[i]);
    }
}

inline int lca(int u, int v) {
    int d = 0;
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = maxp; i > -1; --i) if(dep[fa[v][i]] >= dep[u]) v = fa[v][i];
    if(v == u) return v;
    for(int i = maxp; i > -1; --i) if(fa[v][i] != fa[u][i]) v = fa[v][i], u = fa[u][i];
    return fa[u][0];
}

int w[maxn], ans[maxn];
inline void dfs_ans(int pre, int cur) {
    ans[cur] = w[cur];
    for(int i = head[cur]; i != -1; i = nex[i])
     	if(ver[i] != pre) {
            dfs_ans(cur, ver[i]);
            ans[cur] += ans[ver[i]];
     	}
}

inline bool check(int len) {
    memset(w, 0, sizeof(w));
    int cnt = 0, md = 0;
    for(int i = 0; i < m; i++) {
        if(d[i] > len) {
            cnt++; md = max(d[i], md);
            w[s[i]]++; w[e[i]]++; w[lc[i]] -= 2;
        }
    }
    dfs_ans(0, 1);
    for(int i = 1; i <= n; i++)
        if(ans[i] == cnt && dis[i] - dis[fa[i][0]] >= md-len)
            return true;
    return false;
}

int main() {
    int u, v, w, l = 0, r = 0;
    scanf("%d %d", &n, &m);
    memset(head, -1, sizeof(head));
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addedge(u, v, w); addedge(v, u, w);
        r += w;
    }
    dfs(0, 1);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", s+i, e+i);
        int ln = lca(s[i], e[i]);
        lc[i] = ln; d[i] = dis[s[i]] + dis[e[i]] - 2 * dis[lc[i]];
    }
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
