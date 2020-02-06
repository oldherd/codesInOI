#include <cstdio>

using namespace std;

inline int max(int a, int b) {
	return a > b ? a : b;	
}

int main() {
	int n, a = 0, b = 0, t;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &t);
		a = max(a, t);
	}
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &t);
		b = max(b, t);	
	}
	printf("%d %d\n", a, b);
	return 0;	
}
