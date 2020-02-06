#include <cstdio>
#include <iostream>

const int maxn = 2510;
int a[maxn][maxn], one1[maxn][maxn], one2[maxn][maxn], sum1[maxn][maxn], sum2[maxn][maxn], n, m;
const int sz = 1<<20;
char buf[sz], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,sz,stdin),p1==p2)?EOF:*p1++; }
inline void read(int &x) {
	char ch = gc(); x = 0;
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x = (x<<3) + (x<<1) + (ch&15), ch = gc();
}
inline void go(int &x) {
	char ch = gc();
	while(ch != '0' && ch != '1') ch = gc();
	x = ch == '0' ? 0 : 1;	
}
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

inline void prework() {
	for(int i = 1; i <= n; i++) one1[i][1] = a[i][1];
	for(int j = 1; j <= m; j++) one1[1][j] = a[1][j];
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= m; j++)
			one1[i][j] = a[i][j] ? one1[i-1][j-1] + 1 : 0;
	for(int i = 1; i <= n; i++) one2[i][m] = a[i][m];
	for(int j = 1; j <= m; j++) one2[1][j] = a[1][j];
	for(int i = 2; i <= n; i++)
		for(int j = m; j > 0; --j)
			one2[i][j] = a[i][j] ? one2[i-1][j+1] + 1 : 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			sum1[i][j] = sum1[i-1][j] + sum1[i][j-1] - sum1[i-1][j-1] + a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = m; j > 0; --j)
			sum2[i][j] = sum2[i-1][j] + sum2[i][j+1] - sum2[i-1][j+1] + a[i][j];
}

inline bool spd1(int i, int j, int k) {
	if(i < k || j < k) return false;
	return sum1[i][j] - sum1[i-k][j] - sum1[i][j-k] + sum1[i-k][j-k] == k;
}

inline bool spd2(int i, int j, int k) {
	if(i + k  > n + 1 || j + k > m + 1) return false;
	return sum2[i][j] - sum2[i-k][j] - sum2[i][j+k] + sum2[i-k][j+k] == k;
}

inline bool calc(int k) {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if((spd1(i, j, k) && one1[i][j] >= k) || (spd2(i, j, k) && one2[i][j] >= k))
				return true;		
		}
	return false;
}

int main() {
	bool flag = false;
	read(n); read(m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			go(a[i][j]);
			flag = flag || a[i][j];
		}
	if(!flag) {
		printf("0\n"); 
		return 0;
	}
	prework();
	int l = 1, r = min(n, m);
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(calc(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l); 
	return 0;
}
