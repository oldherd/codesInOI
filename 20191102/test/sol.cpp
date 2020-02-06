#include <cstdio>
#include <cstring>

using namespace std;

const int N = 123456;
int box[N], high;
int ans[200][N];

void add() {
	bool flag = true;
	++box[0];
	while(flag) {
		flag = false;
		for(int i = 0; i <= high; ++i) {
			if(box[i] > 1) box[i] -= 2, ++box[i + 1], flag = true;
		}
		for(int i = high + 1; ; ++i) 
			if(box[i]) ++high, flag = true;
			else break;
		for(int i = 1; i <= high; ++i) {
			if(box[i] && box[i-1]) {
				--box[i]; --box[i-1];
				++box[i+1];
				flag = true;
			}
		}
	}
}

int main() {
	box[0] = 0; high = 0;
	for(int i = 1; i <= 100; ++i) {
		add();
		memcpy(ans[i], box, sizeof(box));
		ans[i][100000] = high;
		for(int j = 1; j <= high; ++j) ans[i][j] ^= ans[i-1][j]; 
		for(int i = 1; i < 18-high; ++i) printf(" ");
		for(int j = high; ~j; --j) printf("%d", ans[i][j]);
		printf("\n");	
	}
	return 0;	
}
