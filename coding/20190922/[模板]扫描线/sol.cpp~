#include <iostream>
#include <algorithm>
#define ull unsigned long long

using namespace std;

const int maxn=100010;

struct Dec{
	int a[maxn<<1],tot;
	Dec(){ tot=0; }
	void add(int v) { a[tot++]=v; }
	void prework() { sort(a,a+tot); tot=unique(a+1,a+tot)-a; }
	int row(int x) { return a[x-1]; }
	int idx(int v) {
		int l=0,r=tot-1,mid;
		while(l<r) {
			mid=(l+r)>>1;
			if(a[mid]==v) return l;
			else if(a[mid]<v) l=mid+1;
			else r=mid-1;
		}
		return l;
	}	//make index from 1 to meet SegTree
}d;

struct line{
	int y1,y2,x,f;
	line() {}
	line(int Y1, int Y2, int X, int F):y1(Y1),y2(Y2),x(X),f(F){}
	bool operator<(const line&o) const{ return x<o.x; }
}l[maxn<<1];

struct segTree{
	int cnt[maxn<<2],len[maxn<<2];
	void update(int p, int lp, int rp) {
		if(cnt[p]>0) len[p]+=d.row(rp+1)-d.row(lp);
		else len[p]=len[p<<1]+len[p<<1|1];
	}
	void cg(int p, int lp, int rp, int l, int r, int f) {
		if(l<=lp&&rp<=r) {
			cnt[p]+=f; update(p,lp,rp);
			return;
		}
		int mid=(lp+rp)>>1;
		if(l<=mid) cg(p<<1,lp,mid,l,r,f);
		if(r>mid) cg(p<<1|1,mid+1,rp,l,r,f);
		update(p,lp,rp);
	}
	int qry() { return len[1]; }
}stree;

int main() {
	ios::sync_with_stdio(false);
	ull ans=0;
	int n,m,x1,y1,x2,y2,xt=0;
	cin>>n; m=n<<1;
	for(int i=0; i<n; i++) {
		cin>>x1>>y1>>x2>>y2;
		l[i<<1]=line(y1,y2,x1,1);
		l[i<<1|1]=line(y1,y2,x2,-1);
		d.add(x1); d.add(x2);
	}
	d.prework(); sort(l,l+m);
	for(int i=0; i<m; i++) {	
		ans+=(ull)(l[i].x-xt)*(stree.qry());
		xt=l[i].x; stree.cg(1,1,d.tot-1,d.idx(l[i].y1),d.idx(l[i].y2),l[i].f);
	}
	cout<<ans<<endl;
	return 0;
}	 
