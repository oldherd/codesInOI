#include <cstdio>
#include <cstring>
#define gc() (p1==p2 && (p2=(p1=buf)+fread(buf, 1, 3000000, stdin), p1==p2) ? EOF : *p1++)
using namespace std;

char buf[3000000], *p1 = buf, *p2 = buf;

inline int read() {
    int x = 0; char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + (ch & 15); ch = gc(); }
    return x;
}

int g[60][60][100], d[60][60];

int main() {
  memset(d, -1, sizeof(d));
  memset(g, 0, sizeof(g));
  int n = read(), m = read(), u, v;
  while(m--) {
    u = read(); v = read();
    g[u][v][0] = 1; d[u][v] = 1;
  }
  for(int p = 1; p < 70; p++)
    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	  if(g[i][k][p-1] && g[k][j][p-1]) {
	    g[i][j][p] = 1; d[i][j] = 1;
	  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
	if(d[i][k] != -1 && d[k][j] != -1 && (d[i][j] == -1 || d[i][j] > d[i][k] + d[k][j])) {
	  d[i][j] = d[i][k] + d[k][j];
	}
  printf("%d\n", d[1][n]);
  return 0;
}
