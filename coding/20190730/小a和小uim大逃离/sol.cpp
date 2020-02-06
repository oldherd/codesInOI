#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 810, maxm = 810, maxk = 16, p = 1000000007;

int f[maxn][maxm][maxk][2];
int a[maxn][maxm];

int main() {
	int n, m, k;
	long long ans = 0;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			f[i][j][a[i][j]][0]++;
			f[i][j][a[i][j]][0] %= p;
			for(int t = 0; t <= k; t++) {
				if(i-1 > 0) {
					f[i][j][t][0] += f[i-1][j][(t-a[i][j]+k+1)%(k+1)][1];
					f[i][j][t][1] += f[i-1][j][(t+a[i][j])%(k+1)][0];
					f[i][j][t][0] %= p; f[i][j][t][1] %= p;
				}
				if(j-1 > 0) {
					f[i][j][t][0] += f[i][j-1][(t-a[i][j]+k+1)%(k+1)][1];
					f[i][j][t][1] += f[i][j-1][(t+a[i][j])%(k+1)][0];
					f[i][j][t][0] %= p; f[i][j][t][1] %= p; 
				}
			}
			ans = (ans + f[i][j][0][1]) % p;
		} 
	printf("%lld\n", ans);
	return 0;
}
