#include <iostream>

using namespace std;

bool a[1000000];

int main() {
	ios::sync_with_stdio(false);
	int n, sum = 12, cnt = 5;
	cin >> n;
	a[1] = a[3] = a[2] = a[6] = true;
	cout << "1 3 2 6 ";
	for(int i = 1; i <= n; i++, cnt++) {
		bool flag = false;
		for(int j = 4; j <= 10000; j++)
			if(!a[j] && !((sum+j) % cnt)) {
				sum += j; cout << j << " "; a[j] = true;
				flag = true;
				break;
			}
		if(!flag) {
			cerr << "Error" << endl;
			break;
		}
	}
	return 0;	
}
