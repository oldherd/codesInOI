#include <iostream>

using namespace std;

int a[10000], b[10000];

int main() {
	int tot = 1, ttt;
	while(cin >> ttt) {
		a[tot] = ttt + a[tot-1];
		b[tot] = a[tot] / tot;
		tot++;
	}
	for(int i = 1; i <= tot; i++) cout << a[i] << " ";
	cout << endl;
	for(int i = 1; i <= tot; i++) {
		if(b[i] != b[i-1]) cout << endl;
		cout << b[i] << " ";
	}
	return 0;
}
