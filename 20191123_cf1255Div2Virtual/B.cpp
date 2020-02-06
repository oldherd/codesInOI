#include <cstdio>

using namespace std;

int main() {
	int t, n, m, ans, tmp;
	scanf("%d", &t);
	while(t--) {
		ans = 0;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &tmp);
			ans += tmp;
		}
		ans <<= 1;
		if(n == 2 || m < n) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", ans);
		for(int i = 1; i < n; ++i) printf("%d %d\n", i, i + 1);
		printf("%d %d\n", n, 1);
	}
	return 0;
}
