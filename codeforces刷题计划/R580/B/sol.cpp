#include <iostream>

using namespace std;

int main() {
	int n, zero = 0, ng = 0, t;
	long long cost = 0;
	cin >> n;
	while(n--) {
		cin >> t;
		if(t >= 1) {
			cost += t - 1;
		} else if(t <= -1) {
			ng^=1; cost += -1 - t;	
		} else {
			zero++;
		}
	}
	cost += zero;
	if(ng % 2 && !zero) cost += 2;
	cout << cost << endl;
	return 0;	
}
