#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, n1, n2, tmp;
	bool flg;
	cin >> t;
	while(t--) {
		flg = false;
		cin >> n >> n1 >> n2;
		for(int i = 1; i <= n1; ++i) {
			cin >> tmp;
			if(tmp == n) flg = true;
		}
		for(int i = 1; i <= n2; ++i) cin >> tmp;
		if(flg) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
