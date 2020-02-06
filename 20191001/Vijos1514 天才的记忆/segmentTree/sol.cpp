#include <iostream>

using namespace std;

const int maxn=210000,inf=0x3f3f3f3f;
int a[maxn];
struct stree{
	int val[maxn<<2];
	void build(int p, int lp, int rp) {
		if(lp==rp) { val[p]=a[lp]; return; }
		int mid=(lp+rp)>>1;
		build(p<<1,lp,mid);
		build(p<<1|1,mid+1,rp);
		val[p]=max(val[p<<1],val[p<<1|1]);
	}
	int query(int p, int lp, int rp, int l, int r) {
		if(l<=lp&&rp<=r) return val[p];
		int mid=(lp+rp)>>1,ans=-inf;
		if(l<=mid) ans=query(p<<1,lp,mid,l,r);
		if(r>mid) ans=max(ans,query(p<<1|1,mid+1,rp,l,r));
		return ans;
	}
}t;

int main() {
	ios::sync_with_stdio(false);
	int n,m,l,r;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	t.build(1,1,n);
	cin>>m;
	while(m--) {
		cin>>l>>r;
		cout<<t.query(1,1,n,l,r)<<endl;	
	}
	return 0;	
}
