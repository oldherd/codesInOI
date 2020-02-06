#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, tmp, lst, pls;
	bool flg = false;
	cin >> t;
	while(t--) {
		cin >> n >> lst;
		flg = false;
		for(int i = 2; i <= n; ++i) {
			cin >> tmp;
			if(abs(tmp - lst) >= 2) {
				pls = i;
				flg = true;
			}
			lst = tmp;
		}
		if(flg) cout << "YES\n" << pls - 1 << ' ' << pls << '\n';
		else cout << "NO\n";
	}
	return 0;
}
