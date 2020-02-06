#include <iostream>
#include <map> 

using namespace std;

map<string, bool> h;

string s;

int main() {
	freopen("mtest.in", "r", stdin);
	freopen("mtest.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	while(n--) {
		cin >> s;
		h[s] = true;	
	}
	cin >> n;
	while(n--) {
		cin >> s;
		if(h[s]) cnt++, h[s] = false;	
	}
	cout << cnt << endl;
	return 0;
}
