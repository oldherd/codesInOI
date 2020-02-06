#include <cstdio>

using namespace std;

const int maxn = 300010;
const long long lf = 6666666666666666666;
int a[maxn];
long long f[maxn][15];

inline long long max(long long x, long long y) {
	return x > y ? x : y;	
}

int main() {
	int n, m, k;
	long long ans = 0;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++) scanf("%d", a+i);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			f[i][j] = -lf;
	f[0][0] = a[0] - k; ans = max(ans, a[0] - k);
	for(int i = 1; i < n; i++) {
		f[i][0] = max(f[i-1][m-1] + a[i], a[i]) - k;
		ans = max(ans, f[i][0]);
		for(int j = 1; j < m; j++) {
			f[i][j] = f[i-1][j-1] + a[i];
			ans = max(ans, f[i][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
