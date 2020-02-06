#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

const int maxn = 2e5+10;
int w[maxn],col[maxn],fa[maxn],blk[maxn],wt[maxn],tot;
vector<int> v1,v2,id1,id2;

struct edge{
	int u,v,w;
	edge() {}
	edge(int U, int V, int W): u(U), v(V), w(W) {}
}e[maxn];

int gf(int x) { return x==fa[x]?x:fa[x]=gf(fa[x]); }
void mg(int x, int y) { 
	x=gf(x); y=gf(y); fa[x]=y;
	if(!blk[y]) blk[y]=blk[x];
	if(!wt[y]) wt[y]=wt[x];
}

int main() {
	ios::sync_with_stdio(false);
	int n,c,s;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin>>c>>s;
		w[i]=s; col[i]=c;
		fa[i]=i; c?wt[i]=i:blk[i]=i;
		if(c) v1.pb(s), id1.pb(i);
		else v2.pb(s), id2.pb(i);
	}
	int p1=0,p2=0;
	while(p1<v1.size()&&p2<v2.size()) {
		if(v1[p1]==v2[p2]) {
			e[tot++]=edge(id1[p1],id2[p2],v1[p1]);
			mg(id1[p1],id2[p2]); p1++; p2++;
		}else if(v1[p1]<v2[p2]) {
			e[tot++]=edge(id1[p1],id2[p2],v1[p1]);
			v2[p2]-=v1[p1]; mg(id1[p1],id2[p2]); p1++;	
		} else {
			e[tot++]=edge(id1[p1],id2[p2],v2[p2]);
			v1[p1]-=v2[p2]; mg(id1[p1],id2[p2]); p2++;	
		}
	}
	int f=gf(1);
	for(int i=2; i<=n; i++) {
		int t=gf(i);
		if(t!=f) {
			if(blk[t]&&wt[f])
				e[tot++]=edge(blk[t],wt[f],0);
			else
				e[tot++]=edge(wt[t],blk[f],0);
			mg(t,f);
		}
	}
	for(int i=0; i<tot; i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
	return 0;
}
