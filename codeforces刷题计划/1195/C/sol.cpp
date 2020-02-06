#include <cstdio>

using namespace std;

const int maxn = 100010;
int h[2][maxn];
long long f[maxn][2][2];

inline long long max(long long x, long long y) {
	return x > y ? x : y;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &h[0][i]);
	for(int i = 1; i <= n; i++) scanf("%d", &h[1][i]);
	f[1][0][0] = 0; f[1][1][0] = h[0][0]; f[1][0][1] = h[1][1];
	for(int i = 1; i <= n; i++) {
		f[i][1][0] = max(f[i-1][0][1], f[i-1][0][0]) + h[0][i];
		f[i][0][1] = max(f[i-1][1][0], f[i-1][0][0]) + h[1][i];
		f[i][0][0] = max(max(f[i-1][0][1], f[i-1][1][0]), f[i-1][0][0]);
	}
	printf("%lld\n", max(max(f[n][0][0], f[n][0][1]), f[n][1][0]));
	return 0;
}
