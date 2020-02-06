#include <cstdio>

using namespace std;

const int maxn = 200010;
int a[maxn], c[maxn];

int main() {
	int n;
	bool flag = true, cg = false;
	scanf("%d %d %d", &n, a+1, a+2);
	c[2] = a[2] > a[1] ? 1 : 0;
	for(int i = 3; i <= n; i++) {
		scanf("%d", a+i);
		if(!flag) continue;
		c[i] = a[i] > a[i-1] ? 1 : 0;
		if(c[i] ^ c[i-1]) {
			if(c[i-1]) {
				if(cg) flag = false;
				else cg = true;
			} else flag = false;
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;	
}
