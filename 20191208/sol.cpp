#include <cstdio>

using namespace std;

const int N = 456789;
int a[N];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, gl, sl, bl, gn, sn, cnt = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);
		for(int i = 2; i <= n / 2; ++i) {
			if(a[i] != a[i - 1]) ++cnt;
		}
		if(cnt < 3) {
			printf("0 0 0\n");
			continue;
		}
		if(a[n / 2] == a[n / 2 + 1]) bl = a[n / 2] + 1;
		else bl = a[n / 2];
		gl = a[1];
		int p = 1;
		cnt = 0;
		while((p == 1 || a[p] == a[p-1]) && a[p] >= bl) ++cnt, ++p;
		if(cnt > n / 2 / 3) {
			printf("0 0 0\n");
			continue;
		}
		gl = a[p - 1]; gn = cnt; cnt = 0;
		while(a[p] >= bl) {
			++cnt, ++p;
			if(a[p] != a[p-1] && cnt > gn) break;
		}
		sn = cnt; sl = a[p - 1]; cnt = 0;
		while(a[p] >= bl) ++cnt, ++p;
		if(cnt <= gn || sn <= gn) {
			printf("0 0 0\n");
		} else {
			printf("%d %d %d\n", gn, sn, cnt);
		}
	}
	return 0;
}
