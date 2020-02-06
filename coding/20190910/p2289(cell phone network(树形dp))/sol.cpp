#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 10010, inf = 0x3f3f3f3f;
inline int min(int x, int y) { return x < y ? x : y; }

int head[maxn], ver[maxn<<1], nex[maxn<<1], ans[maxn][3], tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;	
}

inline void dfs(int pre, int cur) {
    bool leaf = true, flag = false;
    int delta = inf;
    ans[cur][1] = 1; ans[cur][0] = 0;
    for(int i = head[cur]; i != -1; i = nex[i])
		if(ver[i] != pre) {
	  	 	leaf = false;
	 	 	dfs(cur, ver[i]);
	    	if(ans[cur][0] < inf) ans[cur][0] += ans[ver[i]][2];
	    	ans[cur][1] += min(ans[ver[i]][0], min(ans[ver[i]][1], ans[ver[i]][2]));
	    	if(ans[ver[i]][1] <= ans[ver[i]][2]) {
				ans[cur][2] += ans[ver[i]][1]; flag = true;
	    	} else {
				ans[cur][2] += ans[ver[i]][2];
				delta = min(delta, ans[ver[i]][1] - ans[ver[i]][2]);
	    	}
		}
    if(!flag) ans[cur][2] += delta;
    if(leaf) ans[cur][2] = inf;
}

int main() {
    ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    int n, u, v;
    cin >> n;
    for(int i = 1; i < n; i++) {
	cin >> u >> v;
	addedge(u, v);
    }
    dfs(1, 1);
    cout << min(ans[1][1], ans[1][2]) << endl;
    return 0;
}
