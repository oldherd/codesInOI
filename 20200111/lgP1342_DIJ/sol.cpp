#include <iostream>
#include <cstring>
#include <queue>
#define ll long long

using namespace std;

const ll inf = 10000000000000010;
const int N = 1234567, M = 1234567;
ll wei[M << 1];
int head[N << 1], ver[M << 1], nex[M << 1], tot;

inline void addedge(int u, int v, int w) {
    ver[tot] = v; wei[tot] = w; nex[tot] = head[u]; head[u] = tot++;
}

struct noded {
    ll dis;
    int x;
    noded(ll DIS, int X): dis(DIS), x(X) {}
    bool operator > (const noded& o) const { return dis > o.dis; }
};
priority_queue< noded, vector<noded>, greater<noded> > q;
ll dis[N << 1];
void dij(int s) {
    dis[s] = 0;
    q.push(noded(0, s));
    while(!q.empty()) {
        noded cur = q.top(); q.pop();
        if(dis[cur.x] < cur.dis) continue;
        for(int i = head[cur.x]; ~i; i = nex[i]) {
            if(dis[ver[i]] > dis[cur.x] + wei[i]) {
                dis[ver[i]] = dis[cur.x] + wei[i];
                q.push(noded(dis[ver[i]], ver[i]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(head, -1, sizeof(head));
    ll u, ans;
    int n, m, v, w;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v + n, u + n, w);
    }
    for(int i = 1; i <= (n << 1); ++i) dis[i] = inf;
    dij(1);
    ans = 0;
    for(int i = 2; i <= n; ++i) ans += dis[i];
    dij(n + 1);
    for(int i = n + 2; i <= (n << 1); ++i) ans += dis[i];
    cout << ans << '\n';
    return 0;
}
