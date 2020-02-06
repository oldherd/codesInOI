#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=16000,maxl=33000;

struct pt{
	int x,y,z;
	bool operator < (const pt& o) const { return (x==o.x)?(y<o.y):(x<o.x); }
}p[maxn];
int ans[maxn],c[maxl],n;
inline void add(int x, int d) {
	for(;x<32001;x+=x&(-x)) c[x]+=d;
}
inline int qry(int x) {
	int ans=0;
	for(;x;x-=x&(-x)) ans+=c[x];
	return ans;
}

int main() {
	int x,y,pp=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &x, &y);
		p[i].x=x; p[i].y=y;
	}
	sort(p+1,p+n+1);
	for(int i=1; i<=n; i++) {
		if(p[i].x==p[i-1].x&&p[i].y==p[i-1].y) {
			p[pp-1].z++;
		} else {
			p[pp].x=p[i].x; p[pp].y=p[i].y;
			p[pp++].z=1;
		}
	}
	//for(int i=0; i<pp; i++) printf("(%d,%d,%d)\n",p[i].x,p[i].y,p[i].z);
	for(int i=0; i<pp; i++) {
		ans[qry(p[i].y)]+=p[i].z;
		add(p[i].y,p[i].z);
	}
	for(int i=0; i<n; i++) printf("%d\n", ans[i]);
	return 0;
}
