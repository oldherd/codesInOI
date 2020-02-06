#include <cstdio>
#include <algorithm>

using namespace std;

const int maxk = 110, maxn = 20;
double f[maxk][(1<<16)+10];
int w[maxn], pre[maxn];

int main() {
	int k, n, tmp;
	scanf("%d %d", &k, &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", w+i);
		while(scanf("%d", &tmp) && tmp)
			pre[i] |= 1<<(tmp-1);
	}
	for(int i = k, end = 1<<n; i > 0; --i)
		for(int j = 0; j < end; j++) {
			for(int tt = 1; tt <= n; tt++)
				if((pre[tt]&j)==pre[tt])
					f[i][j] += max(f[i+1][j|(1<<(tt-1))]+w[tt], f[i+1][j]);
				else
					f[i][j] += f[i+1][j]; 
			f[i][j] /= n;
		}
	printf("%.6f\n", f[1][0]);
	return 0;	
}
