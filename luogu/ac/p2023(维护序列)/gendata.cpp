#include <bits/stdc++.h>

using namespace std;

const int maxn = 8, maxm = 6;

inline int rd(int m) {
	return (long long)rand() * rand() % m;	
}

inline void swap(int &i, int &j) {
	int t = i; i = j; j = t;	
}

int main() {
	srand((unsigned)time(0));
	int n = rd(maxn-3) + 3, p = rd(10000) + 10000;
	printf("%d %d\n", n, p);
	for(int i = 1; i <= n; i++) printf("%d ", rd(10) + 5);
	int m = rd(maxm-3) + 3;
	printf("\n%d\n", m);
	int op, t, g, c;
	m--;
	while(m--) {
		op = rd(3) + 1; t = rd(n) + 1; g = rd(n) + 1;
		if(t > g) swap(t, g);
		if(op != 3) c = rd(10) + 5, printf("%d %d %d %d\n", op, t, g, c);
		else printf("%d %d %d\n", op, t, g);
	}
	printf("%d %d %d\n", 3, t, g);
	return 0;
}
