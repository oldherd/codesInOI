#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define pdi pair<double, int>
#define max(x, y) (x) > (y) ? (x) : (y)

using namespace std;

const int maxn = 210, maxm = 80010, inf = 0x3f3f3f3f;

int x[maxn], y[maxm], n;

int head[maxn], ver[maxm], nex[maxm], tot;
double wei[maxm];

inline void addedge(int u, int v, double w) {
    ver[tot] = v; wei[tot] = w; nex[tot] = head[u]; head[u] = tot++;
}

priority_queue<pdi> q, EQ;

int pre[maxn];
double d[maxn];
inline void dij1() {
    d[1] = 0; pre[1] = 0; q.push(make_pair(0, 1));
    while(!q.empty()) {
        int cur = q.top().second;
        double dmen = -q.top().first;
        q.pop();
        if(d[cur] < dmen) continue;
        for(int i = head[cur]; i != -1; i = nex[i])
            if(d[cur] + wei[i] < d[ver[i]]) {
                pre[ver[i]] = cur;
                d[ver[i]] = d[cur] + wei[i];
                q.push(make_pair(-d[ver[i]], ver[i]));
            }
    }
}

inline void dij2(int ue, int ve) {
    q = EQ;
    d[1] = 0; pre[1] = 0; q.push(make_pair(0, 1));
    while(!q.empty()) {
        int cur = q.top().second;
        double dmen = -q.top().first;
        q.pop();
        if(d[cur] < dmen) continue;
        for(int i = head[cur]; i != -1; i = nex[i])
            if(d[cur] + wei[i] < d[ver[i]] && ((ue != cur || ve != ver[i]) && (ue != ver[i] || ve != cur))) {
                d[ver[i]] = d[cur] + wei[i];
                q.push(make_pair(-d[ver[i]], ver[i]));
            }
    }
}

int main() {
    int m, u, v;
    double w;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d %d", x+i, y+i);
    memset(head, -1, sizeof(head));
    while(m--) {
        scanf("%d %d", &u, &v);
        w = sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
        addedge(u, v, w); addedge(v, u, w);
    }
    for(int i = 1; i <= n; i++) d[i] = inf;
    dij1();
    double ans = inf;
    for(int p = n; pre[p] != 0; p = pre[p]) {
        for(int i = 1; i <= n; i++) d[i] = inf;
        dij2(p, pre[p]);
        ans = min(ans, d[n]);
    }
    ans == inf ? printf("-1\n") : printf("%.2f\n", d[n]);
    return 0;
}
