#include <cstdio>

using namespace std;

inline int gcd(int a, int b) {
	int t;
	while(b) {
		t = b; b = a % b; a = t;
	}
	return a;
}

int main() {
	int t, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		if(a == 1 || b == 1 || gcd(a, b) == 1) {
			printf("Finite\n");
		} else {
			printf("Infinite\n");
		}
	} 
	return 0;	
}
