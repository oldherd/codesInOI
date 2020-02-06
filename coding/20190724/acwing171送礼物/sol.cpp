#include <cstdio> 
#include <algorithm>

using namespace std;

const int maxn = 60, maxt = (1<<23) + 10;
int g[maxn], ans1[maxt], p, w, n, mid, ans;

inline bool cmp1(int x, int y) {
	return x > y;	
}

inline int bound(int l, int r, int x) {
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(ans1[mid] <= x) l = mid;
		else r = mid - 1;
	}
	return ans1[l];
}

void dfs1(int cur, long long wn) {
	if(wn > w) return;
	if(cur == mid + 1) {
		ans1[p++] = wn;
		return;
	}
	dfs1(cur+1, wn+g[cur]);
	dfs1(cur+1, wn);
}

void dfs2(int cur, long long wn) {
	if(wn > w) return;
	if(cur == n + 1) {
		int cur = bound(0, p-1, w-wn);
		if(cur + wn <= w && cur + wn > ans)
			ans = cur + wn;
		return;
	}
	dfs2(cur+1, wn+g[cur]);
	dfs2(cur+1, wn);
}

int main() {
	scanf("%d %d", &w, &n);
	mid = n / 2 + 1;
	for(int i = 1; i <= n; i++) scanf("%d", g+i);
	sort(g+1, g+n+1, cmp1);
	dfs1(1, 0);
	ans = 0;
	sort(ans1, ans1+p);
	dfs2(mid+1, 0);
	printf("%d\n", ans);
	return 0;	
}
