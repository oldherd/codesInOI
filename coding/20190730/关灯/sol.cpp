#include <cstdio>
#include <cstring> 

using namespace std;

const int maxn = 60; 

int f[maxn][maxn][2], pl[maxn], wei[maxn], s[maxn];

inline int min(int x, int y) { return x < y ? x : y; } 

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i = 1; i <= n; i++) scanf("%d %d", pl+i, wei+i);
	s[1] = wei[1];
	for(int i = 2; i <= n; i++) s[i] = s[i-1] + wei[i];
	memset(f, 0x3f3f3f3f, sizeof(f));
	f[c][c][0] = f[c][c][1] = 0;
	for(int len = 2; len <= n; len++)
		for(int l = 1; l+len <= n+1; l++) {
			int r = len + l - 1;
			f[l][r][0] = min(f[l+1][r][0] + (pl[l+1]-pl[l])*(s[n]-s[r]+s[l]), f[l+1][r][1] + (pl[r]-pl[l])*(s[n]-s[r]+s[l]));
			f[l][r][1] = min(f[l][r-1][0] + (pl[r]-pl[l])*(s[n]-s[r-1]+s[l-1]), f[l][r-1][1] + (pl[r]-pl[r-1])*(s[n]-s[r-1]+s[l-1]));
			//printf("f[%d][%d][0] = %d, f[%d][%d][1] = %d\n", l, r, f[l][r][0], l, r, f[l][r][1]);
		}
	printf("%d\n", min(f[1][n][0], f[1][n][1]));
	return 0;
}
