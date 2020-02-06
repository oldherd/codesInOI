#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=16000,maxl=33000;

struct pt{ int x,y; } p[maxn];
int n,c[maxl],ans[maxn];
inline void cg(int x) { for(;x<32001;x+=x&(-x)) c[x]++; }
inline int qry(int x) { int ans=0; for(;x;x-=x&(-x)) ans+=c[x]; return ans; }

inline bool cmp(pt i, pt j) { return (i.x==j.x)?(i.y<j.y):(i.x<j.x); }

int main() {
	int x,y;
	scanf("%d", &n);
	for(int i=0; i<n ;i++) {
		scanf("%d %d",&x,&y);	
		p[i].x=x; p[i].y=y;
	}
	sort(p,p+n,cmp);
	for(int i=0; i<n; i++) {
		ans[qry(p[i].y)]++;
		cg(p[i].y);
	}
	for(int i=0; i<n; i++) printf("%d\n",ans[i]);
	return 0;
}
