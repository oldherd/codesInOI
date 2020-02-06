#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1<<20;

struct line{
	int x1,x2,y,f;
	line() {}
	line(int X1, int X2, int Y, int F):x1(X1),x2(X2),y(Y),f(F){}
}l[maxn<<1];

struct decIndex{
	int a[maxn<<1],tot;
	decIndex() { tot=0; }
	void add(int x) { a[tot++]=x; }
	void prework() { sort(a,a+tot); tot=unique(a,a+tot)-a; }
	int row(int idx) { return a[idx]; }
	int idx(int num) { return lower_bound(a,a+tot,num)-a; }
}d;

struct segTree{
	int cnt[maxn<<2], l[maxn<<2], r[maxn<<2], len[maxn<<2];
	void update(int p) { 
		cur[p]=cur[p<<1]+cur[p<<1|1];
		len[p]=len[p<<1]+len[p<<1|1];
	}
	void build(int p, int lp, int rp) {
		l[p]=lp; r[p]=rp; cnt[p]=len[p]=0;
		if(l==r) return;
		int mid=(lp+rp)>>1;
		build(p<<1,lp,mid);
		build(p<<1|1,mid+1,rp);
	}
	void change(int p, int lp, int rp) {
		if(lp<=l[p]&&r[p]<=rp) {
			cnt[p]++; len[p]=d.row(r[p]+1)-d.row(l[p]);
			return;
		}
		int mid=(l[p]+r[p])>>1;
		if(lp<=mid) change(p<<1,lp,mid);
		if(rp>mid) change(p<<1|1,mid+1,rp);
		update(p);
	}
	int qry(int p, int lp, int rp) {
		if(lp<=l[p]&&r[p]<=rp) return len[p];
		int mid=(l[p]+r[p])>>1, ans=0;
		if(lp<=mid) ans+=qry(p<<1,lp,mid);
		if(rp>mid) ans+=qry(p<<1|1,mid+1,rp);
		return ans;
	}
}stre;

int main() {
	ios::sync_with_stdio(false);
	int n,m,x1,y1,x2,y2;
	cin >> n; m=n<<1;
	for(int i=0; i<n; i++) {
		cin>>x1>>y1>>x2>>y2;
		l[i<<1]=line(x2,x1,y2,1);
		l[i<<1|1]=line(x2,x1,y1,-1);
		d.add(x1); d.add(x2);
	}
	sort(l,l+m);
	int lst=0;
	for(int i=0; i<m; i++) {
		
	}
	return 0;	
}
