#include <cstdio>

using namespace std;

char buf[2000000], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin), p1==p2)?EOF:*p1++; }

int main() {
	int n = 0;
	bool flag = true, f2 = false;
	char ch = gc();
	while(ch != '1' && ch != '0') 
		ch = gc();
	if(ch == '0') {
		putchar('0'); putchar('\n');
		return 0;		
	}
	while(ch == '0' || ch == '1') {
		ch = gc();
		if(flag && ch == '1') flag = false;
		++n;
		f2 = true;
	}
	if(f2) --n;
	if(!(n%2) && flag) n /= 2;
	else n = n / 2 + 1;
	printf("%d\n", n);
	return 0;
}

