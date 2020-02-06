#include <cstdio>

using namespace std;

const int maxn = 2510, maxm = 2510; 
int a[maxn][maxm], zeroL[maxn][maxm], zeroR[maxn][maxm], f1[maxn][maxm], f2[maxn][maxm];

inline int min(int i, int j) { return i < j ? i : j; }
inline int max(int i, int j) { return i > j ? i : j; }

int main() {
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			if(!ans && a[i][j]) ans = 1;
		}
	for(int i = 1; i <= n; i++) zeroL[i][1] = zeroR[i][1] = 1;
	for(int j = 1; j <= m; j++) zeroL[1][j] = zeroR[1][j] = 1;
	for(int i = 1; i <= n; i++) f1[i][1] = a[i][1];
	for(int j = 1; j <= m; j++) f1[1][j] = a[1][j];
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= m; j++) {
			zeroL[i][j] = a[i][j-1] == 1 ? 1 : zeroL[i][j-1] + 1;
			zeroR[i][j] = a[i-1][j] == 1 ? 1 : zeroR[i-1][j] + 1;
		}
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= m; j++) {
			if(!a[i][j]) continue;
			f1[i][j] = min(min(f1[i-1][j-1]+1, zeroL[i][j]), zeroR[i][j]);
			ans = max(ans, f1[i][j]);
		}
	for(int i = 1; i <= n; i++) zeroL[i][m] = 1;
	for(int i = 1; i <= n; i++) f2[i][m] = a[i][m];
	for(int j = 1; j <= m; j++) f2[1][j] = a[1][j];
	for(int i = 2; i <= n; i++)
		for(int j = m-1; j > 0; --j)
			zeroL[i][j] = a[i][j+1] == 1 ? 1 : zeroL[i][j+1] + 1;
	for(int i = 2; i <= n; i++)
		for(int j = m-1; j > 0; --j) {
			if(!a[i][j]) continue;
			f2[i][j] = min(f2[i-1][j+1]+1, min(zeroL[i][j], zeroR[i][j]));
			ans = max(ans, f2[i][j]);
		}
	printf("%d\n", ans);
	return 0;
}
