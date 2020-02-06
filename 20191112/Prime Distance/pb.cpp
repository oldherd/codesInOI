#include <cstdio>

using namespace std;

const int N = 1e8;
int cv[N];

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		if(!cv[i]) {
			for(int j = i; j <= n / i; ++j) cv[i*j] = 1;
			++cnt;
		}
	}
	printf("%d\n", cnt);
	return 0;	
}
