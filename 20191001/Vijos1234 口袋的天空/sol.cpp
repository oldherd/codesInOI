#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=1100, maxm=11000;

struct edge{
	int x,y,w;
	bool operator < (const edge& o) const { return w<o.w; }
}e[maxm];

int fa[maxn];
int gf(int x) { return x==fa[x]?x:fa[x]=gf(fa[x]); }
inline void un(int x, int y) { x=gf(x); y=gf(y); fa[x]=y; }

int main() {
	int n,m,k,x,y,w,jd,cst=0;
	scanf("%d %d %d", &n,&m,&k);
	jd=n;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=0; i<m; i++) {
		scanf("%d %d %d",&x,&y,&w);
		e[i].x=x; e[i].y=y; e[i].w=w;
	}
	sort(e,e+m);
	for(int i=0; i<m&&jd!=k; i++) {
		if(gf(e[i].x)!=gf(e[i].y)) {
			cst+=e[i].w; jd--;
			un(e[i].x,e[i].y);
		}
	}
	printf("%d\n", cst);
	return 0;
}
