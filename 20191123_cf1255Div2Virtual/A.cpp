#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int t, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		int dis = abs(a - b);
		int step = 0;
		step += dis / 5;
		dis %= 5;
		step += dis / 2;
		dis %= 2;
		step += dis;
		printf("%d\n", step);
	}
	return 0;	
}
