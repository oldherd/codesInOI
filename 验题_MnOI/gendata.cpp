#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int rd(int n) {
	return (ull)rand() * rand() % n;
}

const int mt = 250, mzb = 5, mp = 10, mk = 1, mtt = 300;
const char ptp[2] = {'W', 'J'}, ztp[4] = {'P', 'L', 'T', 'G'};

int main() {
	freopen("pvztt.in", "w", stdout);
	srand((unsigned)time(0));
	int t = 10, n, m, k;
	cout << t << endl;
	while(t--) {
		m = rd(mzb)+5;
		n = rd(mp)+1;
		k = rd(mk)+1;
		cout << n << " " << m << " " << k << endl;
		int maxt = rd(mtt)+1;
		for(int i = 1; i <= n; i++) {
			int type = rd(2);
			cout << ptp[type] << " " << rd(maxt>10?maxt/10:maxt)+1 << " " << rd(5)+1 << " " << rd(9)+1 << endl;
		}
		for(int i = 1; i <= m; i++) {
			int type = rd(4);
			cout << ztp[type] << " " << rd(maxt)+1 << " " << rd(5)+1 << " " << rd(4)+6 << endl;
		}
		for(int i = 1; i <= k; i++) {
			cout << rd(maxt)+1 << " " << rd(9)+1 << endl;
		}
	}
	return 0;
}
