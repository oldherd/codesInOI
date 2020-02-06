#include <iostream>
#include  <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 510, maxm = maxn*maxn;
double f[maxn][maxn], s[maxn], e[maxm];
int head[maxn], deg[maxn], ver[maxm<<1], nex[maxm<<1], ut[maxm], vt[maxm], tot, n;

inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

void gauss() {
	for(int i = 1, k = 1; i <= n; i++, k = i) {
		for(int j = i+1; j <= n; j++) if(fabs(f[j][i])>fabs(f[k][i])) k = j;
		if(i != k) swap(f[i], f[k]); swap(s[i], s[k]);
		for(int j = 1; j <= n; j++) if(i != j) {
			double z = f[j][i] / f[i][i];
			for(int k = i; k <= n; k++) f[j][k] -= z * f[i][k];
			s[j] -= s[i] * z;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 
	memset(head, -1, sizeof(head));
	double ans = 0;
	int m, u, v;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v;
		addedge(u, v); addedge(v, u);
		deg[u]++; deg[v]++; ut[i] = u; vt[i] = v;
	}
	for(int i = 1; i < n; i++) {
		for(int j = head[i]; j != -1; j = nex[j]) if(ver[j] != n)
			f[i][ver[j]] = (double)1 / deg[ver[j]];
		f[i][i] = -1;
	}
	s[1] = -1; s[n] = 1; f[n][n] = 1;
	gauss();
	for(int i = 1; i <= m; i++) {
		if(ut[i] != n) e[i] += s[ut[i]] / f[ut[i]][ut[i]] / deg[ut[i]];
		if(vt[i] != n) e[i] += s[vt[i]] / f[vt[i]][vt[i]] / deg[vt[i]];
	}
	sort(e+1, e+m+1);
	for(int i = 1; i <= m; i++)
		ans += e[i] * (m-i+1);
	printf("%.3f\n", ans);
	return 0;
}
