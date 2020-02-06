#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	int t, a, b, n, ans;
	cin >> t;
	while(t--) {
		cin >> a >> b >> n;
		ans = 0;
		if(n==0 || n==1) {
			cout << (n?b:a) << endl;
			continue;	
		}
		if(n%3!=1) ans ^= a;
		if(n%3) ans ^= b;
		cout << ans << endl;
	}
	return 0;	
}
