#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

string s;
int num[30], a[30], au = 0;

double search(int x, int y) {
	if(y > 30) return 0;
	if(a[0] + x == 0 || a[1] - x == 0)
		return y/pow(2,y);
	return search(x-1, y+1) + search(x+1, y+1);
}

int main() {
	cin >> s;
	double at;
	int n = s.length();
	while(cin>>at);
	for(int i = 0; i < n; i++)
		++num[s[i]-'A'];
	for(int i = 0; i < 28; i++) if(num[i]) a[au++] = num[i];
	if(au == 1) cout << "0.0" << endl;
	else if(au == 2) printf("%.1f", search(0, 0));
	return 0;	
}
