#include <cstdio>
#define ull unsigned long long

using namespace std;

inline ull gcd(ull a, ull b) { while(b^=a^=b^=a%=b); return a; }

int main() {
	ull a = 0, b = 0, c = 1, g, tmp;	//a_c^b
	int n, la = 1, lc = 1;
	scanf("%d", &n);
	for(int i = n; i > 0; --i) {	//\frac{n}{i}
		b = b*i + c*n; c = c*i;
		a += b / c; b %= c;
		g = gcd(b, c); b /= g; c /= g;
	}
	if(b) {
		tmp = a; while(tmp /= 10) la++;
		tmp = c; while(tmp /= 10) lc++;
		for(int i = 0; i < la; i++) putchar(' ');
		printf("%llu\n", b);
		printf("%llu", a);
		for(int i = 0; i < lc; i++) putchar('-');
		putchar('\n');
		for(int i = 0; i < la; i++) putchar(' ');
		printf("%llu\n", c);
	} else {
		printf("%llu\n", a);	
	}
	return 0;
}
