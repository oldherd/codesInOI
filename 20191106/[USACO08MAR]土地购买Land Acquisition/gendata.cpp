#include <bits/stdc++.h>

using namespace std;

inline int rd(int m) {
	return rand() * rand() % m;
}

int main() {
//	freopen("data.in", "w", stdout);
	int n = 50000;
	printf("%d\n", n);
	for(int i = 1; i <= n; ++i) {
		printf("%d %d\n", rd(500000) + 1, rd(500000) + 1);
	}
	return 0;	
}
