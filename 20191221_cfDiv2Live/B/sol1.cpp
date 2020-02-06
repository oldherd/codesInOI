#include <iostream>
#define ll unsigned long long

using namespace std;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) {
		x = 1; y = 0; return a;
	}
	ll g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a = 0, b = 0, x, y, n, m, tmp;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> tmp;
		a += tmp;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> tmp;
		b += tmp;
	}
//	cout << a <<" " << b << '\n';
	ll gcd = exgcd(n, m, x, y);
	x *= (b - a) / gcd;
	x = ( (x % m) + m ) % m;
	cout << x << '\n';
	return 0;
}

