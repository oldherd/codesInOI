#include <cstdio>
#include <algorithm>

using namespace std;

const double eps = 1-8;
const int maxn = 15;
double a[maxn][maxn], sgm[maxn], f[maxn][maxn], s[maxn];

int n;

inline double fabs(double t) {
	return t < 0 ? -t : t;
}

void gauss() {
	for(int i = 1, k = 1; i <= n; i++, k = i) {
		for(int j = i+1; j <= n; j++) if(fabs(f[k][i]) < fabs(f[j][i])) k = j;
		if(fabs(f[k][i]) < eps) continue;
		if(k != i) { swap(f[i], f[k]); swap(s[i], s[k]); }
		for(int j = 1; j <= n; j++)
			if(j != i && fabs(f[j][i]) > eps) {
				double z = f[j][i] / f[i][i];
				for(int k = i; k <= n; k++) f[j][k] -= z * f[i][k];
				s[j] -= z * s[i];
			}
	}
}

int main() {
	double t;
	scanf("%d", &n);
	for(int i = 1; i <= n+1; i++) {
		t = 0;
		for(int j = 1; j <= n; j++) {
			scanf("%lf", &a[i][j]);
			t += a[i][j]*a[i][j];
		}
		sgm[i] = t / 2;
	}
	for(int i = 2; i <= n+1; i++) {
		for(int j = 1; j <= n; j++)
			f[i-1][j] = a[1][j] - a[i][j];
		s[i-1] = sgm[1] - sgm[i];
	}
	gauss();
	for(int i = 1; i <= n; i++)
		printf("%.3f ", s[i] / f[i][i]);
	printf("\n");
	return 0;
}
