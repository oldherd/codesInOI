#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1234;
int a[maxn];

bool uexi(int key, int l, int r) {
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(a[mid] <= key) l = mid;
		else r = mid - 1;
	}
	return a[l] != key;
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, s, k;
		cin >> n >> s >> k;
		for(int i = 1; i <= k; ++i) cin >> a[i];
		sort(a + 1, a + k + 1);
		if(uexi(s, 1, k)) {
			cout << "0\n";
			continue;
		}
		for(int i = 1; i <= k; ++i) {
			if(s - i > 0 && uexi(s - i, 1, k)) {
				cout << i << '\n';
				break;
			} else if(s + i <= n && uexi(s + i, 1, k)) {
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}
