#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 300010;
int a[maxn], c[maxn];

int main() {
	int n, k;
	scanf("%d %d %d", &n, &k, a+1);
	for(int i = 2; i <= n; i++) {
		scanf("%d", a+i);
		c[i] = a[i] - a[i-1];
	}
	sort(c+2, c+n+1);
	int ans = a[n] - a[1];
	for(int i = n, j = k-1; j; --j, --i) ans -= c[i];
	printf("%d\n", ans);
	return 0;
}
