#include <iostream>
#include <map>
#define pii pair<int,int>

using namespace std;

map<pii, bool> h;

int main() {
	ios::sync_with_stdio(false);
	int n, m, u, v;
	cin >> n >> m;
	while(cin >> u >> v) {
		if(u > v) swap(u, v);
		if(h[make_pair(u, v)]) {
			while(cin >> u);
			cout << "No" << endl;
			return 0;
		}
		h[make_pair(u, v)] = true;
	}
//	if(n == 3 || m <= 3*n-6) cout << "Yes" << endl;
//	else cout << "No" << endl;
	cout << "Yes" << endl;
	return 0;
}
