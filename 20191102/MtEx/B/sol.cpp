#include <cstdio>

using namespace std;

inline int fabs(int x) {
	return x > 0 ? x : -x;
}

int main() {
	register int n, m, cnt = 0, flg;
	register int fmt[5][3];
	scanf("%d %d", &n, &m);
	for(register int i = 0; i < n; ++i) scanf("%d %d %d", &fmt[i][0], &fmt[i][1], &fmt[i][2]);
	if(m > 500) m = 500;
	for(register int x = 1; x <= m; ++x) {
		for(register int y = 1; y <= m; ++y) {
			for(register int z = 1; z <= m; ++z) {
				flg = 1;
				for(register int k = 0; flg && k < n; ++k)
					(fabs(fmt[k][0] - x) ^ fabs(fmt[k][1] - y) ^ fabs(fmt[k][2] - z)) != 9 && (flg = 0);
				flg && ++cnt;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
