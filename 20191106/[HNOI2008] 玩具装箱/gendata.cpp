#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline int rd(int m) {
	return (ll)rand() * rand() % m;
}

int main() {
//	freopen("data.in", "w", stdout);
	srand((unsigned)time(0));
	int n = rd(5000)+1, l = rd(1e7)+1;
	printf("%d %d\n", n, l);
	for(int i = 1; i <= n; ++i) printf("%d\n", rd(1e7)+1);
	return 0;	
}
