#include <iostream>
#include <cstring>

using namespace std;

const int N = 123456, M = 567890;
int head[N], ver[M], nex[M], my[M], tot;
inline void addedge(int u, int v) {
    ver[tot] = v; my[tot] = u; nex[tot] = head[u]; head[u] = tot++;
}

int co[N], dfn[N], low[N], sta[N], ind[N], top, dfs_clock = 1, col = 1;
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
        while(sta[--top] != cur) {
            co[sta[top]] = col;
        }
        co[cur] = col++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(head, -1, sizeof(head));
    memset(ind, 0, sizeof(ind));
    int n, m, u, v, cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        if(u != v) addedge(u, v);
    }
    for(int i = 1; i <= n; ++i) if(!co[i]) tarjan(i);
    for(int i = 0; i < tot; ++i) if(co[my[i]] != co[ver[i]]) ind[co[ver[i]]] = 1;
    for(int i = 1; i < col; ++i)
        if(!ind[i]) ++cnt;
    cout << max(cnt, 1) << '\n';
    return 0;
}
