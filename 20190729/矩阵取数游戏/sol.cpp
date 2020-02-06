#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const char ct[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', };
const int size = 50, maxn = 100, maxm = 100;
int a[maxn][maxm];

struct bignum{
	int data[size], end;
	bignum() { memset(data, 0, sizeof(data)); end = -1; }
	bignum operator = (int o) { 
		end = -1;
		while(o) { data[++end] = o % 10; o /= 10; }
		return *this;
	}
	bignum operator = (const bignum &o) {
		end = o.end;
		for(int i = 0; i <= end; i++) data[i] = o.data[i];
		return *this;
	}
	bignum operator + (const bignum &o) const {
		bignum res; res.end = end > o.end ? end : o.end;
		for(int i = 0; i <= res.end; i++) {
			if(i <= end) res.data[i] += data[i];
			if(i <= o.end) res.data[i] += o.data[i];
			if(res.data[i] >= 10) {
				res.data[i] %= 10; res.data[i+1]++;	
			}
		}
		if(res.data[res.end+1]) ++res.end;
		return res;
	}
	bignum operator * (const int o) const {
		bignum res; res.end = end;
		int t = 0;
		for(int i = 0; i <= end; i++) {
			res.data[i] = data[i] * o + t;
			t = res.data[i] / 10;
			res.data[i] %= 10;
		}
		while(t) { res.data[++res.end] = t % 10; t /= 10; }
		return res;
	}
	bool operator < (const bignum &o) const {
		if(end != o.end) return end < o.end;
		for(int i = end; i > -1; --i) if(data[i] != o.data[i]) return data[i] < o.data[i];
		return false;
	}
	bool operator > (const bignum &o) const {
		if(end != o.end) return end > o.end;
		for(int i = end; i > -1; --i) if(data[i] != o.data[i]) return data[i] > o.data[i];
		return false;
	}
	bool operator == (const bignum &o) const {
		if(end != o.end) return false;
		for(int i = end; i > -1; --i) if(data[i] != o.data[i]) return false;
		return true;
	}
	void output() {	for(int i = end; i > -1; --i) putchar(ct[data[i]]);	}
}f[maxm][maxm], p2[maxm];

int main() {
	int n, m;
	bignum res;
	scanf("%d %d", &n, &m);
	p2[1] = 2;
	for(int i = 2; i <= maxm; i++) p2[i] = p2[i-1] * 2;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) { scanf("%d", &a[i][j]); f[j][j] = p2[m] * a[i][j]; }
		for(int len = 2; len <= m; len++)
			for(int l = 1; l <= m-len+1; l++) {
				int r = len + l - 1;
				f[l][r] = max(f[l+1][r] + p2[m-r+l]*a[i][l], f[l][r-1] + p2[m-r+l]*a[i][r]);
			}
		res = res + f[1][m];
	}
	res.output(); putchar('\n');
	return 0;
}
