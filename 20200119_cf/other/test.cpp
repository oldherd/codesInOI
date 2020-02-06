#include <iostream>

using namespace std;

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n, t;
	cin >> n;
	double a1 = 0, a2 = 0, a3 = 0;
	for(int i = 1; i <= n; ++i) {
		a1 += (double)n / i;
	}
	t = n;
	while(t > 0) {
		a2 += (double)(t >> 1) / t;
		if(!(t >> 1)) a2 += 1, --t;
		else t -= t >> 1;
	}
	t = n;
	while(t > 0) {
		a3 += (double)(t + 1 >> 1) / t;
		if(!(t + 1 >> 1)) a2 += 1, --t;
		else t -= t + 1 >> 1;
	}
	cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
	return 0;	
}
