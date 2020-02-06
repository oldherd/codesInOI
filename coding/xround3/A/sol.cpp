#include <iostream> 

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	long long a, b, n;
	cin >> a >> b >> n;
	cout << (a * n + n * (n-1) / 2 * (b-a)) << endl;
	return 0;	
}
