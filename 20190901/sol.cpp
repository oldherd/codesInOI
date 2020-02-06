#include <iostream>
#define ull unsigned long long

using namespace std;

const int maxt = (1<<10)+10;
ull f[15][90][maxt];
int cot[maxt];

int main() {
	ios::sync_with_stdio(false);
	ull ans = 0;
	int n, k, end, tmp;
	cin >> n >> k;
	end = 1<<n;
	for(int i = 0; i < end; i++)
		for(tmp = i; tmp&(-tmp); tmp -= tmp&(-tmp)) cot[i]++;
	f[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k; j++)
			for(int l = 0; l < end; l++)
				if(!((l<<1)&l) && !((l>>1)&l))
					for(int m = 0; m < end; m++)
						if(cot[l] + cot[m] <= j && !((m<<1)&m) && !((m>>1)&m) && !(m&l) && !((m<<1)&l) && !((m>>1)&l))
							f[i][j][l] += f[i-1][j-cot[l]][m];

	for(int s = 0; s < end; s++) ans += f[n][k][s];
	cout << ans << endl;
	return 0;
}
