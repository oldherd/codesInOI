#include <cstdio>
#define ll long long

using namespace std;

const ll INF = 1e17 + 10;
const int N = 2345;

ll xi[N], yi[N], w[N], dis[N], vis[N], tlen;
int u[N], v[N], po[N], pre[N], etot, ptot, n;
inline ll min(ll x, ll y) { return x < y ? x : y; } 
inline ll fabs(ll x) { return x < 0 ? -x : x; }
inline ll getdis(int x, int y) { return (fabs(xi[x] - xi[y]) +  fabs(yi[x] - yi[y])) * (w[x] + w[y]); }
inline void addans(int x, int y) { u[etot] = x; v[etot++] = y; }
inline void addpo(int x) { po[ptot++] = x; }
inline void prim() {
	int cur = 0; dis[0] = INF;
	for(int i = 1; i <= n; ++i) if(dis[cur] > dis[i]) cur = i;
	tlen += dis[cur]; vis[cur] = 1;
	addpo(cur);
	for(int i = 1; i <= n; ++i) if(!vis[i]) {
		ll w = getdis(cur, i);
		if(w < dis[i]) dis[i] = w, pre[i] = cur;
	}
	for(int i = 1; i < n; ++i) {
		cur = 0;
		for(int i = 1; i <= n; ++i) if(!vis[i] && dis[i] < dis[cur]) cur = i;
		tlen += dis[cur];
		if(pre[cur]) addans(pre[cur], cur);
		else addpo(cur);
		vis[cur] = 1;
		for(int i = 1; i <= n; ++i) if(!vis[i]) {
			ll w = getdis(cur, i);
			if(w < dis[i]) dis[i] = w, pre[i] = cur;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld %lld", xi + i, yi + i);
	for(int i = 1; i <= n; ++i) scanf("%lld", dis + i);
	for(int i = 1; i <= n; ++i) scanf("%lld", w + i);
	prim();
	printf("%lld\n%d\n", tlen, ptot);
	for(int i = 0; i < ptot; ++i) printf("%d ", po[i]);
	printf("\n");
	printf("%d\n", etot);
	for(int i = 0; i < etot; ++i)
		printf("%d %d\n", u[i], v[i]);
	return 0;
}
