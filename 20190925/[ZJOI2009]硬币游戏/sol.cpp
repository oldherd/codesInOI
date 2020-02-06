#include <iostream>

using namespace std;

const int maxn=10000;
int a[maxn][2];

int main() {
	ios::sync_with_stdio(false);
	int n,t,now=1;
	cin>>n>>t;
	for(int i=1; i<=n; i++) cin>>a[i][0],--a[i][0];
	for(int i=1; i<=n; i++) cout<<a[i][0]<<" ";
	cout<<endl;
	while(t--) {
		for(int i=1; i<=n; ++i)
			a[i][now]=a[i][now^1]^a[(i%n)+1][now^1];
		for(int i=1; i<=n; i++) cout<<a[i][now]<<" ";
		cout<<endl; now^=1;
	}
	return 0;	
}
