#include <iostream>

using namespace std;

const int maxn=110;
int fa[maxn], dis[maxn];
int gf(int x) { 
	if(x==fa[x]) return x;
	int t=gf(fa[x]);
	dis[x]+=dis[fa[x]];
	return fa[x]=t;
}
inline void un(int x, int y, int w) { 	//x-y==w
	gf(x); dis[fa[x]]=w-dis[x];
	fa[fa[x]]=y;
}

int main() {
	ios::sync_with_stdio(false);
	int t,n,m,d1,d2,w,flg;
	cin>>t;
	while(t--) {
		cin>>n>>m; flg=1;
		for(int i=0; i<=n; i++) fa[i]=i,dis[i]=0;
		while(m--) {
			cin>>d1>>d2>>w;		//d2-(d1-1)==w
			if(flg) {
				if(gf(d1-1)==gf(d2)) {
					if(dis[d2]-dis[d1-1]!=w)
						flg=0;
				} else {
					un(d2,d1-1,w);
					gf(d2); gf(d1-1);
				}
			}
		}
		if(flg) cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
	return 0;	
}
