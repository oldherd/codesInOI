#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#define int long long

using namespace std;

const int V = 2345678, inf = 0x3f3f3f3f;
signed cv[V], lr[V];

signed main() {
	int l, r;
	while(2 == scanf("%lld %lld", &l, &r)) {
		memset(cv, 0, sizeof(cv));
		memset(lr, 0, sizeof(lr));
		if(l <= 1000000) {
			for(int i = 2; i <= r; ++i) {
				if(!cv[i]) {
					for(int j = i; j <= r / i; ++j) cv[i*j] = 1;
				}
			}
			int lst, cnt = 0, a, b, c, d, dismin = inf, dismax = 0;
			for(int i = l; i <= r; ++i)
				if(!cv[i]) {
					if(cnt) {
						int dis = i - lst;
						if(dis < dismin) {
							dismin = dis;
							a = lst, b = i;
						}
						if(dis > dismax) {
							c = lst, d = i;
						}
					} else {
						lst = i;
					}
					++cnt;
				}
			if(cnt < 2) {
				printf("There are no adjacent primes.\n");
			} else {
				printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a, b, c, d);
			}
		} else {
			int to = sqrt(r);
			for(int i = 2; i <= to; ++i) {
				if(!cv[i]) {
					for(int j = i; j <= to / i; ++j) cv[i*j] = 1;
					for(int k = l / i; k <= r / i; ++k) {
						if(k*i >= l) lr[k*i-l] = 1;
					}
				}
			}
			int lst, cnt = 0, a, b, c, d, dismin = inf, dismax = 0;
			for(int i = l; i <= r; ++i) {
				if(!lr[i-l]) {
					if(cnt) {
						int dis = i - lst;
						if(dismin > dis) {
							dismin = dis;
							a = lst, b = i;
						}
						if(dismax < dis) {
							dismax = dis;
							c = lst, d = i;
						}
					} else {
						lst = i;
					}
					++cnt;
				}
			}
			if(cnt < 2) {
				printf("There are no adjacent primes.\n");
			} else {
				printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a, b, c, d);
			}
		}
	}
	return 0;
}
