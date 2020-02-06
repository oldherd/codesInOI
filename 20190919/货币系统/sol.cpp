#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110, maxa = 25010;
int a[maxn], f[maxa];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		memset(f, 0, sizeof(f)); f[0] = 1;
		int n, ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		for(int i = 1; i <= n; i++) {
			if(!f[a[i]]) ans++;
			for(int j = a[i]; j <= a[n]; j++)
				if(f[j-a[i]]) f[j] = 1;
		}
		cout << ans << endl;
	}
	return 0;
}
