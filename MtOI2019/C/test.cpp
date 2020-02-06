#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 110;
const double eps = 1e-8;
double f[maxn][maxn], s[maxn];

void print(int n) {
	cout << "#########################" << endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)	printf("  %4.3f", f[i][j]);
		cout << "|" << s[i] << endl;
	}
	cout << "#########################" << endl;
}

bool gauss(int n) {
	double del;
	print(n);
	for(int i = 1, k = 1; i <= n; i++, k = i) {
		for(int j = i+1; j <= n; j++) if(fabs(f[k][i]) < fabs(f[j][i])) k = j;
		print(n);
		if(fabs(del = f[k][i]) < eps)continue;	//多组解或无解 
		if(k != i) { swap(f[i], f[k]); swap(s[i], s[k]); }
		print(n);
		for(int j = i; j <= n; j++) f[i][j] /= del; s[i] /= del;
		for(int k = 1; k <= n; k++)
			if(k != i) {
				del = f[k][i];
				for(int j = 1; j <= n; j++) f[k][j] -= f[i][j] *del;
				s[k] -= s[i]*del;	
			}
		print(n);
	}
	return true;
}

//1.000  -1.000  0.000  0.000  0.000|5
//  0.250  -1.000  0.750  0.000  0.000|-1.66667
//  0.000  0.333  -1.000  0.667  0.000|-1.66667
//  0.000  0.000  0.375  -1.000  0.625|-2.5
//  0.000  0.000  0.000  0.000  1.000|0

int main() {
	ios::sync_with_stdio(false);
	int n;
	n = 5;
	f[1][1] = 1; f[1][2] = -1; s[1] = (double)5 / 2;
	f[2][1] = 0.25; f[2][2] = -1; f[2][3] = 0.75; s[2] = -(double)5/3;
	f[3][2] = (double)1/3; f[3][3] = -1; f[3][4] = (double)2/3; s[3] = -(double)5/3;
	f[4][3] = 0.375; f[4][4] = -1; f[4][5] = 0.625; s[4] = -2.5;
	f[5][5] = 1; s[5] = 0;
	if(!gauss(n)) cout << "No Solution" << endl;
	else 
		for(int i = 1; i <= n; i++)
			printf("%.2f\n", s[i] / f[i][i]);
	return 0;
}
