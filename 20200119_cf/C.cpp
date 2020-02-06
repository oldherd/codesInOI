#include <cstdio>
#include <bitset>

using namespace std;

bitset<100100> s11, s12, s13, s2;


int main() {
	int n, q, r, c;
	scanf("%d %d", &n, &q);
	while(q--) {
		scanf("%d %d", &r, &c);
		if(r == 1) {
			s11.flip(c);
			if(c - 1 > 0) s12.flip(c - 1);
			if(c + 1 <= n) s13.flip(c + 1);
		} else {
			s2.flip(c);
		}
		if((s11 & s2).none() && (s12 & s2).none() && (s13 & s2).none()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;	
}
