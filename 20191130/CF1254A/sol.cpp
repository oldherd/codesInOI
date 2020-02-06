#include <cstdio>

using namespace std;

const char name[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int N = 123;

inline int read() {
	char ch = getchar();
	while(ch != '.' && ch != 'R') ch = getchar();
	return ch == 'R';
}

int a[N][N];
char res[N][N];

inline void getpt(int r, int c, int id, int &xi, int &yi) {
	xi = (id - 1) / c + 1, yi = xi % 2 ? id - (xi-1) * c : c - (id - (xi-1) * c) + 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int sum = 0, r, c, k, xi, yi;
		scanf("%d %d %d", &r, &c, &k);
		for(int i = 1; i <= r; ++i)
			for(int j = 1; j <= c; ++j) {
				a[i][j] = read();
				sum += a[i][j];
			}
		if(!k) {
			for(int i = 1; i <= k; ++i) {
				getpt(r, c, i, xi, yi);
				res[xi][yi] = name[i];
			}
			for(int i = k + 1; i <= r * c; ++i) {
				getpt(r, c, i, xi, yi);
				res[xi][yi] = name[k];
			}
		} else {
			int one = sum / k, ls = sum % k, rs = k - ls;
			int i = 1, pp = 1, tmp = 0;
			for(; i <= r * c; ++i) {
				if(pp > k) break;
				getpt(r, c, i, xi, yi);
				res[xi][yi] = name[pp]; tmp += a[xi][yi];
				if(tmp == one + 1 && ls > 0 || rs > 0 && tmp == one) {
					if(tmp == one) --rs;
					else --ls;
					tmp = 0; ++pp;
				}
			}
			for(; i <= r * c; ++i) {
				getpt(r, c, i, xi, yi);
				res[xi][yi] = name[k];
			}
		}
		for(int i = 1; i <= r; ++i) {
			for(int j = 1; j <= c; ++j) {
				printf("%c", res[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

