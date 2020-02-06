#include <iostream>

const int maxm = 1010, cs = 10;
int s[maxm][cs];

int main() {
	int n, m, ans = 0;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			char ch;
			while(std::cin >> ch && (ch < 'A' || ch > 'E'));
			s[j][ch-'A']++;			
		}
	for(int j = 1; j <= m; j++) {
		int t, m = 0;
		std::cin >> t;
		for(int i = 1; i < 5; ++i) if(s[j][i] > s[j][m]) m = i;
		ans += t * s[j][m];
	}
	std::cout << ans << std::endl;
	return 0;
}
