#include <cstdio>

using namespace std;

char buf[2000000], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin), p1==p2)?EOF:*p1++; }
inline void read(int &x) {
    x = 0;
    char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}

const int maxn = 110, maxm = 1000010;
int dis[maxn][maxn], p[maxm], ans[maxm];

int main() {
	register int n;
	register char ch;
	read(n);
	for(register int i = 1; i <= n; i++)
		for(register int j = 1; j <= n; j++) {
			ch = gc();
			while(ch != '0' && ch != '1') ch = gc();
			dis[i][j] = ch=='1'?1:-1;
		}
	for(register int k = 1; k <= n; k++)
		for(register int i = 1; i <= n; i++)
			for(register int j = 1; j <= n; j++) {
				if(i==j || j==k || k==i || dis[i][k]==-1 || dis[k][j]==-1) continue;
				if(dis[i][j]==-1 || dis[i][j] > dis[i][k]+dis[k][j]) dis[i][j] = dis[i][k] + dis[k][j];
			}
	register int m, au = 1;
	read(m);
	for(register int i = 1; i <= m; i++) read(p[i]);
	ans[0] = p[1];
	int la = 1;
	for(register int i = 2; i < m; i++)
		if(dis[ans[au-1]][p[i+1]] < i+1-la)
			ans[au++] = p[i], la = i;
	ans[au++] = p[m];
	printf("%d\n", au);
	for(register int i = 0; i < au; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

