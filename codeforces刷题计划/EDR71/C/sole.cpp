#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200010;
char str[maxn];
int pp[maxn], pu;

int main() {
	long long ans;
	int n, a, b, t, len, plr;
	char las = '0';
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %s", &n, &a, &b, str);
		las = '0'; pu = 0; len = 1; plr = 2;
		for(int i = 1; i < n; i++) {
			plr += ((str[i]&15)||str[i-1]&15)?2:1;
			if(str[i] == las) len++;
			else {
				pp[pu++] = len;
				las = str[i];
				len = 1;
			}
		}
		pp[pu++] = len;
		ans = (long long)a*n + plr*(long long)b;
		for(int i = 2; i + 1 < pu; i += 2)
			ans += min((pp[i]-1)*(long long)b, (long long)a*2);
		if(pu!=1) ans += 2*a;
		printf("%lld\n", ans);
	}
	return 0;
}
