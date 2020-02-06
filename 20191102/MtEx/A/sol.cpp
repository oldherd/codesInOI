#include <cstdio>

using namespace std;;

const int N = 1010;
int a[N];

inline void read(int &x) {
    x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x=(x<<3)+(x<<1)+(ch&15), ch = getchar();
}

int main() {
	int n, m, k, tmp, stp = 0;
	read(n); read(m); read(k);
	++k;
	while(--k) {
		read(tmp);
		a[tmp] = 1;	
	}
	tmp = 0;
	while(tmp < n) {
		tmp += m; ++stp;
		a[tmp] && ++m;
	}
	printf("%d", stp);
	return 0;
}
