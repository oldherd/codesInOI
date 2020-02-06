#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const int maxn = 2010;
string str;
double f[maxn][maxn], s[maxn], ans;
int num[30], n;

int main() {
	cin >> str;
	while(cin >> ans);
	n = str.length();
	for(int i = 0; i < n; i++) num[str[i]-'A']++;
	for(int i = 1; i <= n-1; i++) {
		f[i][i-1] = (double)(i-1) / (2*i); f[i][i] = -1;
		f[i][i+1] = (double)(i+1) / (2*i);  s[i] = -(double)n*(n-1)/(2*i*(n-i));
	}
	f[n][n] = 1; s[n] = 0;
	for(int i = 1; i <= n-1; i++) {
		if(fabs(f[i+1][i]) < eps) continue;
		double z = f[i+1][i] / f[i][i];
		for(int j = i; j <= n; j++) f[i+1][j] -= z * f[i][j];
		s[i+1] -= z * s[i];
	}
	for(int i = n; i > 1; --i) {
		if(fabs(f[i-1][i]) < eps) continue;
		double z = f[i-1][i] / f[i][i];
		for(int j = i; j <= n; j++) f[i-1][j] -= z * f[i][j];
		s[i-1] -= z * s[i];
	}
	ans = 0;
	for(int i = 0; i <= 'Z'-'A'; i++)
		if(num[i])
 			ans += (double)num[i] / n * s[num[i]] / f[num[i]][num[i]];
	printf("%.1f\n", ans);
	return 0;
}
