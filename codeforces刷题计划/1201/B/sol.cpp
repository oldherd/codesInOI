#include <cstdio>

using namespace std;

int main() {
	int n, p = 0, t, mx = 0;
	long long ans = 0;
	scanf("%d", &n); 
	while(n--) {
		scanf("%d", &t);
		mx = mx > t ? mx : t;
		ans += t;
		p ^= (t%2);
	}
	if(p || mx * 2 > ans) printf("NO\n");
	else printf("YES\n");
	return 0;
} 
