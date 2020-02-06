#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define itra vector<int>::iterator

using namespace std;

const int N = 2345678, M = 123456;

int head[N], ver[N], nex[N], m, tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

int c[N], deg[N], res = 0;
bool cmp(int x, int y) {
	return c[x] + deg[x] < c[y] + deg[y];
}
void dfs(int cur) {
	vector<int> v;
	for(int i = head[cur]; ~i; i = nex[i]) {
		dfs(ver[i]);
		v.push_back(ver[i]);
	}
	sort(v.begin(), v.end(), cmp);
	int tt = c[cur] + deg[cur], delc = 0, deldeg = 0;
	for(itra it = v.begin(); it != v.end(); ++it) {
		if(tt + c[*it] + deg[*it] - 1 <= m) {
			tt += c[*it] + deg[*it] - 1;
			delc += c[*it]; deldeg += deg[*it] - 1;
			++res;
		}
	}
	c[cur] += delc; deg[cur] += deldeg;
}

int main() {
	memset(head, -1, sizeof(head));
	int n, tmp;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", c + i);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", deg + i);
		for(int j = 1; j <= deg[i]; ++j) {
			scanf("%d", &tmp);
			addedge(i, tmp + 1);
		}
	}
	dfs(1);
	printf("%d\n", res); 
	return 0;
}
