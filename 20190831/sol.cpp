#include <iostream>

using namespace std;

const int mt = (1 << 12) + 10, md = 100000000;
int sta[20], f[20][mt];

int main() {
	ios::sync_with_stdio(false);
	int n, m, tmp, ans = 0, ed;
	cin >> n >> m;
	ed = 1<<m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> tmp;
			sta[i] = (sta[i]<<1) | tmp;
		}
	for(int s = 0; s < ed; s++)
		if((sta[1]&s) == s && !(s&(s<<1)) && !(s&(s>>1)))
			f[1][s] = 1;
	for(int i = 2; i <= n; i++)
		for(int s = 0; s < ed; s++)
			if(!(s&(s<<1)) && !(s&(s>>1)) && (sta[i] & s) == s)
				for(int j = 0; j < ed; j++)
					if(!(s & j))
						f[i][s] = (f[i-1][j] + f[i][s]) % md;
	for(int s = 0; s < ed; s++) ans = (ans + f[n][s]) % md;
	cout << ans << endl;
	return 0;
}
