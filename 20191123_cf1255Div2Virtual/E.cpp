#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

const ll inf = 0x3f3f3f3f3f3f3f3f;
int a[N], n;

int main() {
	int tot = 0;
	ll ans = inf;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		tot += a[i];
	}
	if(n == 1) {
		printf("-1\n");
		return 0;
	}
	for(int div = 2; div <= sqrt(n); ++div) {
		if(n % div) {
			ll ret = 0, tmp = 0;
			int tot = 0, rt = 0, p = 1;
			while(p <= n) {
			 	while(p <= n && tot <= (div >> 1)) {
			 		tot += a[p];
			 		++p; tmp += tot;
				}
				while(p <= n && rt + tot <= div) {
					rt += a[p]; tmp += tot;
					++p;
				}
				tot = rt = 0;
			} 
		}
	}
	ans = min(ans, calc(n));
	printf("%lld\n", ans); 
	return 0;	
}
