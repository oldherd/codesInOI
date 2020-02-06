#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200010;
int a[maxn], u[maxn], n;

int main() {
	scanf("%d", &n);
	int p = n*2;
	int ed = 2*n, q = 3*n, z = q / 2;
	bool flag;
	for(int t = p; t >= z; --t) {
		a[0] = 1; a[1] = t; u[1] = 1; u[t] = 1;
		flag = true;
		int e = 0;
		memset(u, 0, sizeof(u));
		for(int i = 0; i < ed; i++, e^=1) {
			if(i+2 <= p) {
				a[(i+2)%p] = q+e+1 - a[(i+1)%p] - a[i%p];
				if(u[a[(i+2)%p]] || a[(i+2)%p] > p) {
					flag = false;
					break;
				}
				u[a[(i+2)%p]] = 1;
			}
			if(a[i%p]+a[(i+1)%p]+a[(i+2)%p] != q+1 && a[i%p]+a[(i+1)%p]+a[(i+2)%p] != q+2) {
				flag = false;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) {
		printf("YES\n");
		for(int i = 0; i < ed; i++) printf("%d ", a[i]);
		printf("\n");
	} else {
		printf("NO\n");	
	}
	return 0;	
}
