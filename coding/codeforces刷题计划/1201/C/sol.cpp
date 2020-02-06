#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 200010;
int a[maxn];

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	int i = (1 + n) >> 1, f = 1;
	while(i < n && k >= (long long)f * (a[i+1]-a[i])) {
		k -= f++ * (a[i+1]-a[i]);
		i++;
	}
	int ans = a[i] + k / f;
	cout << ans << endl;
	return 0;
}
