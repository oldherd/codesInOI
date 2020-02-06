#include <iostream>
#include <string>
#include <map>

using namespace std;

string s;
map<int,int> h;
const int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ye,mt,da;

inline bool check(int i) {
	if(i-6>=0 && i+3<(int)s.length())
		if(s[i+1]=='0' && s[i+2]=='1' && s[i+3]>='3' && s[i+3]<='5')
			if(s[i-1]=='-' && s[i-4]=='-' && isdigit(s[i-2]) && isdigit(s[i-3]))
				if(isdigit(s[i-5])&&isdigit(s[i-6])) {
					int x=(s[i-3]&15)*10+(s[i-2]&15), y=(s[i-6]&15)*10+(s[i-5]&15);
					if(x>=1 && x<=12 && y>=1 && y<=days[x]) {
							mt=x; da=y; ye=2010+(s[i+3]&15);
							return true;
					}
				}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	int len = s.length(), tday, mn, mday, mx=0;
	for(int i = 0; i < len; i++) {
		if(i==66) {
			int t=tday;
			t = tday;
		}
		if(s[i]=='2' && check(i)) {
			tday = ye*10000+mt*100+da;
			mn=++h[tday];
			if(mn>mx) mday=tday,mx=mn;
		}
	}
	ye=mday/10000; mt=(mday%10000)/100; da=mday%100;
	if(da<10) cout<<'0'; cout<<da<<'-';
	if(mt<10) cout<<'0'; cout<<mt<<"-";
	cout<<ye<<endl;
	return 0;	
}
