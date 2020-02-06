#include <cstdio>

using namespace std;

long long a[100010], pn;
int n, m;

int main() {
	int op, t, g, c;
	scanf("%d %lld", &n, &pn);
	for(int i = 1; i <= n; i++) scanf("%lld", a+i), a[i]%=pn;
	scanf("%d", &m);
	while(m--) {
		scanf("%d %d %d", &op, &t, &g);
		if(op != 3) scanf("%d", &c);
		if(op == 1) {
			for(register int i = t; i <= g; i++) {
				a[i]*=c;
				a[i]%=pn;
			}
		} else if(op == 2) {
			for(register int i = t; i <= g; i++) {
				a[i]+=c;
				a[i]%=pn;
			}
		} else {
			long long ans = 0;
			for(;t <= g; t++) ans += a[t];
			printf("%lld\n", ans % pn);
		}
	} 
}
