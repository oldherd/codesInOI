#include <iostream>

using namespace std;

const int maxn=210000;
int a[maxn],k;

struct segTree{
	int val[maxn<<2],laz[maxn<<2];
	void update(int p) { val[p]=max(val[p<<1],val[p<<1|1]); }
	void build(int p, int lp, int rp) {
		if(lp==rp) {
			if(lp+k<=n+1) for(int i=0; i<k; i++) val[p]+=a[i+lp];
			return;
		}
		int mid=(lp+rp)>>1;
		build(p<<1,lp,mid);
		build(p<<1|1,mid+1,r);
		update(p);
	}
	void cg(int p, int lp, int rp, int l, int r, int dlt) {
		if(l<=lp&&rp<=r) {
			laz[p]+=dlt; val[p]+=dlt; return;
		}
		spread(p);
		int mid=(lp+rp)>>1;
		if(l<=mid) cg(p<<1,lp,mid,l,r,dlt);
		if(r>mid) cg(p<<1|1,mid+1,rp,l,r,dlt);
		update(p);
	}
	int qry(int p, int lp, int rp, int l, int r) {
		if(l<=lp&&rp<=r) return val[p];
		int mid=(lp+rp)>>1,ans=-0x3f3f3f3f;
		if(l<=mid) ans=max(ans,qry(p<<1,lp,mid,l,r));
		if(r>mid) ans=max(ans,qry(p<<1|1,mid+1,rp,l,r));
		return ans;
	}
}s;

int main() {
	ios::sync_with_stdio(false);
	int t,n,m,p,x,y;
	cin>>t;
	while(t--) {
		cin>>n>>m>>k;
		for(int i=1; i<=n; i++) cin>>a[i];
		s.build(1,1,n);
		while(m--) {
			cin>>p>>x>>y;
			if(!p) {
				s.cg(1,1,n,x-k+1,x,y-a[x]);
				a[x]=y;
			} else if(p==1) {
				s.cg(1,1,n,x-k+1,x,a[y]-a[x]);
				s.cg(1,1,n,y-k+1,y,a[x]-a[y]);
				swap(a[x],a[y]);
			} else if(p==2) {
				cout<<s.qry(1,1,n,x,y)<<endl;
			}
		}
	}
	return 0;	
}
