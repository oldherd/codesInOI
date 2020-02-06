#include <iostream>

using namespace std;

typedef long long ll;

const ll p = 100003;

ll qp(ll a, ll b) {
	ll ret = 1ll % p;
	for(; b; b >>= 1) {
		if(b & 1) ret = ret * a % p;
		a = a * a % p;
	}
	return ret;
}

int main() {
	ll n, m;
	cin >> m >> n;
	cout << ((qp(m, n) - m * qp(m - 1, n - 1) % p) % p + p) % p << '\n';
	return 0;
}
