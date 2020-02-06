#include <iostream>
#define ull unsigned long long

using namespace std;

const int maxn = 1e5;
int a[maxn];

int main() {
	ios::sync_with_stdio(false);
	int n, m, mid=1, dis=0x3f3f3f3f, dcur;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin>>a[i]; dcur=i<=m?m-i:m+n-i;
		if(a[i]<a[mid]) mid=i, dis=dcur;
		else if(a[i]==a[mid]&&dcur<dis) {
			mid=i; dis=dcur;
		}
	}
	int num = m>=mid?m-mid:m+n-mid;
	if(m<mid) {
		for(int i=mid+1; i<=n; i++) --a[i];
		for(int i=1; i<=m; i++) --a[i];
	} else for(int i=mid+1; i<=m; i++) --a[i];
	for(int i=1; i<=n; i++)
		if(i!=mid) cout<<a[i]-a[mid]<<' ';
		else cout<<(ull)a[mid]*n+num<<' ';
	cout<<endl;
	return 0;
}
