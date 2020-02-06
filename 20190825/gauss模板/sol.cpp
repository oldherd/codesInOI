#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 110;
const double eps = 1e-8;
double f[maxn][maxn], s[maxn];

bool gauss(int n) {
	double del;
	for(int i = 1, k = 1; i <= n; i++, k = i) {
		for(int j = i+1; j <= n; j++) if(fabs(f[k][i]) < fabs(f[j][i])) k = j;
		if(fabs(del = f[k][i]) < eps) return false;	//多组解或无解 
		if(k != i) { swap(f[i], f[k]); swap(s[i], s[k]); }
		for(int j = i; j <= n; j++) f[i][j] /= del; s[i] /= del;
		for(int k = 1; k <= n; k++)
			if(k != i) {
				del = f[k][i];
				for(int j = 1; j <= n; j++) f[k][j] -= f[i][j] *del;
				s[k] -= s[i]*del;	
			}
//		from 17 to 23:
//		for(int j = i+1; j <= n; j++) {
//			double z = f[j][i] / f[i][i];
//			for(int k = i; k <= n; k++) f[j][k]	-= z * f[i][k];
//		}
//		j -> 1 no huidai j -> i+1 huidai && ziyouyuan...
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) cin >> f[i][j];
		cin >> s[i]; 
	}
	if(!gauss(n)) cout << "No Solution" << endl;
	else
		for(int i = 1; i <= n; i++)
			printf("%.2f\n", s[i] / f[i][i]);
	return 0;
}
