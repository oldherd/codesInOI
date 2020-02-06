#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define itra vector<int>::iterator

using namespace std;

const int N = 5678, INF = 0x3f3f3f3f; 
int head[N], ver[N<<1], nex[N<<1], tot, n;
inline void addedge(int u, int v) {
    ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

int sta[N], vis[N], bd[N], top, bp;
bool flg = true;
void find(int cur, int pre) {
    if(!flg) return;
    for(int i = head[cur]; ~i && flg; i = nex[i]) 
        if(ver[i] != pre) {
            if(vis[ver[i]]) {
                flg = false;
                --top;
                while(sta[top] != ver[i])
                    bd[bp++] = sta[top--];
                bd[bp++] = sta[top];
                bd[bp++] = cur;
                return;
            }
            vis[ver[i]] = 1;
            sta[top++] = ver[i];
            find(ver[i], cur);
            if(!flg) return;
            --top;
        }
}

int ans[N], tat[N], ta, b1, b2;
void dfs(int cur, int pre) {
    tat[ta++] = cur;
    vector<int> v;
    for(int i = head[cur]; ~i; i = nex[i])
        if(ver[i] != pre && !(cur==b1&&ver[i]==b2) && !(cur==b2&&ver[i]==b1)) {
            v.push_back(ver[i]);
        }
    sort(v.begin(), v.end());
    for(itra it = v.begin(); it != v.end(); ++it) dfs(*it, cur);
}

inline bool ck() {
    for(int i = 0; i < n; ++i)
        if(ans[i] != tat[i])
            return tat[i] < ans[i];
    return false;
}

inline void upd() {
    if(ck()) {
        for(int i = 0; i < n; ++i) ans[i] = tat[i];
    }
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    ans[0] = INF;
    int m, u, v;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        addedge(u, v); addedge(v, u); 
    }
    if(n == m) {
        top = bp = 0;
        vis[1] = 1;
        sta[top++] = 1;
        find(1, 0);
        for(int i = 0; i < bp - 1; ++i) {
            b1 = bd[i], b2 = bd[i+1];
            ta = 0;
            dfs(1, 0);
            upd();
        }
        for(int i = 0; i < n; ++i) printf("%d ", ans[i]);
        printf("\n");
    } else {
        dfs(1, 0);
        for(int i = 0; i < n; ++i) printf("%d ", tat[i]);
        printf("\n");
    }
    return 0;
}
