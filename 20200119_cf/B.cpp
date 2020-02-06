#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	double ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i) ans += (double)1 / i;
	cout << ans << '\n';
	return 0;
}
