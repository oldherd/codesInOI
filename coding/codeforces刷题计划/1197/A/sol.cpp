#include <cstdio>

using namespace std;

inline int min(int x, int y) { return x < y ? x : y; }

int main() {
	int t, n, m1, m2, tmp;
	scanf("%d", &t);
	while(t--) {
		m1 = -1; m2 = -1;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			if(tmp >= m1) {
				m2 = m1; m1 = tmp;
			} else if(tmp > m2) {
				m2 = tmp;	
			}
		}
		printf("%d\n", min(m2-1, n-2));
	}
	return 0;	
}
