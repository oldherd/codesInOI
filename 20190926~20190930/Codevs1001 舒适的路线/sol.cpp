#include <iostream>
#include <algorithm>

using namespace std;


const int maxn=510,maxm=5100,inf=0x3f3f3f3f;
struct edge{
	int u,v,w;
	bool operator < (const edge& o) const { return w<o.w; }
}e[maxm];

int gcd(int a, int b) { int t; while(b) { t=b; b=a%b; a=t; } return a; }

int fa[maxn],af1=inf,af2=1;
double ad=inf;
inline int gf(int x) {
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
inline void un(int x, int y) {
	x=gf(x); y=gf(y);
	fa[x]=y;
}

int main() {
	ios::sync_with_stdio(false);
	int n,m,u,v,w,s,t,f1,f2,g;
	double d;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>u>>v>>w;
		e[i].u=u; e[i].v=v; e[i].w=w;	
	}
	cin>>s>>t;
	sort(e+1,e+m+1);
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) fa[j]=j;
		for(int j=i; j<=m; j++) { 	
			if(gf(e[j].u)!=gf(e[j].v))
				un(e[j].u,e[j].v);	
			if(gf(s)==gf(t)) {
				f1=e[j].w; f2=e[i].w;
				(ad>(double)f1/f2) && (ad=(double)f1/f2,af1=f1,af2=f2,1);
				break;
			}
		}
	}
	g=gcd(af1,af2); af1/=g; af2/=g;
	af1==0x3f3f3f3f&&af2==1 && (cout<<"IMPOSSIBLE"<<endl,1) || (cout<<af1,af2==1||cout<<"/"<<af2,cout<<endl);
	return 0;
}
