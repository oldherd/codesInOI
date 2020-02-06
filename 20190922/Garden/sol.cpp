#include<iostream>
#include<cstring>

using namespace std;

const int maxn=210000,inf=0x3f3f3f3f;
int a[maxn],sk[maxn],n,k;

struct segTree{
	int val[maxn<<2],laz[maxn<<2];
	void update(int p) { val[p]=max(val[p<<1],val[p<<1|1]); }
	void modify(int p) {
		val[p<<1]+=laz[p]; val[p<<1|1]+=laz[p];
		laz[p<<1]+=laz[p]; laz[p<<1|1]+=laz[p];
		laz[p]=0;
	}
	void build(int p, int lp, int rp) {
		if(lp==rp) {
			val[p]=sk[lp]?sk[lp]:-inf; return;
		}
		int mid=(lp+rp)>>1;
		build(p<<1,lp,mid);
		build(p<<1|1,mid+1,rp);
		update(p); laz[p]=0;
	}
	void cg(int p, int lp, int rp, int l, int r, int dlt) {
		if(l<=lp&&rp<=r) {
			laz[p]+=dlt; val[p]+=dlt;
			return;
		}
		if(laz[p]) modify(p);
		int mid=(lp+rp)>>1;
		if(l<=mid) cg(p<<1,lp,mid,l,r,dlt);
		if(r>mid) cg(p<<1|1,mid+1,rp,l,r,dlt);
		update(p);
	}
	int qry(int p, int lp, int rp, int l, int r) {
		if(l<=lp&&rp<=r) return val[p];
		if(laz[p]) modify(p);
		int mid=(lp+rp)>>1,ans=-inf;
		if(l<=mid) ans=qry(p<<1,lp,mid,l,r);
		if(r>mid) ans=max(ans,qry(p<<1|1,mid+1,rp,l,r));
		return ans;
	}
}s;

int main() {
	ios::sync_with_stdio(false);
	int t,m,p,x,y,tmp;
	cin>>t;
	while(t--) {
		memset(sk,0,sizeof(sk));
		cin>>n>>m>>k; tmp=0;
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=n; i++) {
			tmp+=a[i];
			if(i-k>=1) tmp-=a[i-k];
			if(i-k+1>=1) sk[i-k+1]=tmp;
		}
		s.build(1,1,n);
		while(m--) {
			cin>>p>>x>>y;
			if(!p) {
				s.cg(1,1,n,x-k+1,x,y-a[x]); a[x]=y;
			} else if(p==1) {
				s.cg(1,1,n,max(x-k+1,1),x,a[y]-a[x]);
				s.cg(1,1,n,max(y-k+1,1),y,a[x]-a[y]);
				swap(a[x],a[y]);
			} else {
				cout<<s.qry(1,1,n,x,y-k+1)<<endl;
			}
		}
	}
	return 0;
}
