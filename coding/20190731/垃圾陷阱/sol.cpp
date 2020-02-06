#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

const int maxm =110, maxt = 3010;
int f[maxm][maxt];

struct rub{
	int t, hp, hei;
	bool operator < (const rub &o) const { return t < o.t; }
}a[maxm];

int main() {
	int n, m, ans = -1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i].t, &a[i].hp, &a[i].hei);	
	}
	sort(a+1, a+m+1);
	memset(f, -1, sizeof(f));
	if(a[1].t <= 10) {
		f[1][10-a[1].t] = a[1].hei; 
		f[1][10+a[1].hp-a[1].t] = 0;
		if(a[1].hei >= n) {
			printf("%d\n", a[1].t);
			return 0;
		}
	} else {
		printf("10\n");
		return 0;
	}
	int mt = 10 + a[1].hp, tmp;
	bool flag = true;
	for(int i = 2; i <= m && flag; i++) {
		mt += a[i].hp; tmp = mt - a[i].t;
		if(tmp < 0) {
			printf("%d\n", mt-a[i].hp);
			return 0;
		}
		for(int t = 0; t <= tmp; t++) {
			int dt = t + a[i].t - a[i-1].t;
			if(dt - a[i].hp >= 0)
				if(f[i-1][dt-a[i].hp] != -1) f[i][t] = f[i-1][dt-a[i].hp];
			if(dt > 0 && f[i-1][dt] != -1 && f[i-1][dt] + a[i].hei > f[i][t]) f[i][t] = f[i-1][dt] + a[i].hei;
			if(f[i][t] >= n) {
				ans = a[i].t;
				flag = false;
				break;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int t = 0; t <= mt; t++) printf("%d ", f[i][t]);
		printf("\n");
	}
	if(flag) printf("%d\n", mt);
	else printf("%d\n", ans);
	return 0;
}
