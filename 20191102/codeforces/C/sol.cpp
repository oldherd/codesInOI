#include <cstdio>
#include <cstring>
#define ull unsigned long long

using namespace std;

const int N = 123456, mod = 1e9 + 7;
char s[N];
int f[N];

int main() {
	scanf("%s", s);
	int len = strlen(s);
	s[len] = 'a'; ++len;
	ull ans = 1;
	f[0] = f[1] = 1;
	for(int i = 2; i <= len; ++i) f[i] = (f[i-1] + f[i-2]) % mod;
//	for(int i = 0; i <= len; ++i) printf("%d ", f[i]);
//	printf("\n");
	int leng = 1;
	if(s[0] == 'w' || s[0] == 'm') {
		printf("0\n");
		return 0;
	}
	for(int i = 1; i < len; ++i) {
		if(s[i] == 'w' || s[i] == 'm') {
			printf("0\n");
			return 0;
		}
		if(s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n')) {
			++leng;
		} else {
			if(leng == 1) continue;
			ans = ans * f[leng] % mod;
			leng = 1;
		}
	}
	printf("%llu\n", ans);
	return 0;
}
