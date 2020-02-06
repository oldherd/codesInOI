#include <cstdio>

using namespace std;

const int sz = 2000000, maxn = 100, maxk = 2510	;
char buf[sz], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,sz,stdin), p1==p2)?EOF:*p1++; }
#define gc() getchar()
inline void read(int &x) {
    x = 0; char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}

int a[maxn][maxn], b[maxn][maxn];
int stp[maxk][2], k = 0;

int main() {
	int nx, ny;
	read(nx); read(ny);
	for(int i = 1; i <= nx; i++)
		for(int j = 1; j <= ny; j++)
			read(a[i][j]);
	for(int i = 1; i <= nx; i++)
		for(int j = 1; j <= ny; j++)
			if(a[i][j] && !b[i][j]) {
				if(a[i-1][j-1]&&a[i-1][j]&&a[i][j-1]) {
					b[i][j] = 1; stp[k][0] = i-1; stp[k++][1] = j-1;
					continue;
				}
				if(a[i-1][j]&&a[i-1][j+1]&&a[i][j+1]) {
					b[i][j] = b[i][j+1] = 1; stp[k][0] = i-1; stp[k++][1] = j;
					continue;
				}
				if(a[i][j-1]&&a[i+1][j-1]&&a[i+1][j]) {
					b[i][j] = b[i+1][j-1] = b[i+1][j] = 1;
					stp[k][0] = i; stp[k++][1] = j-1;
					continue;
				}
				if(a[i][j+1]&&a[i+1][j]&&a[i+1][j+1]) {
					b[i][j] = b[i][j+1] = b[i+1][j] = b[i+1][j+1] = 1;
					stp[k][0] = i; stp[k++][1] = j;
					continue;
				}
				printf("-1\n");
				return 0;
			}
	printf("%d\n", k);
	for(int i = 0; i < k; i++)
		printf("%d %d\n", stp[i][0], stp[i][1]);
	return 0;
}


