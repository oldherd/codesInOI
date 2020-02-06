#include <iostream>
#include <cmath>
#define ull unsigned long long

using namespace std;

int main() {
	ull n, k;
	int sqt;
	cin >> n >> k;
	n++; k++;
	sqt = (int)sqrt(k) + 1;
	bool flag = true;
	if(!(k%2) && k != 2) flag = false;
	for(int i = 3; i <= sqt && flag; i += 2)
		if(!(k%i))
			flag = false;
	if(flag) {
		if((k<<1) > n) cout << 1 << endl;
		else cout << 2 << endl;
	} else {
		cout << 2 << endl;	
	}
	return 0;
}
