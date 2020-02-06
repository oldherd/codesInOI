#include <cstdio>
#include <cmath>
#include <iostream>

namespace Mker
{
//  Powered By Kawashiro_Nitori
//  Made In Gensokyo, Nihon
	#include<climits>
	#define ull unsigned long long
	#define uint unsigned int
	ull sd;int op;
	inline void init() {scanf("%llu %d", &sd, &op);}
	inline ull ull_rand()
	{
		sd ^= sd << 43;
		sd ^= sd >> 29;
		sd ^= sd << 34;
		return sd;
	}
	inline ull rand()
	{
		if (op == 0) return ull_rand() % USHRT_MAX + 1;
		if (op == 1) return ull_rand() % UINT_MAX + 1; 
		if (op == 2) return ull_rand();
	}
}

using namespace std;

const long long t = 3;
const int p = 1e9+7, maxn = 1000000;
long long a[maxn], pw[maxn];

int main() {
	int t, n;
	long long res = 0;
	scanf("%d", &t);
	Mker::init();
	a[0] = -3; a[1] = -6; a[2] = -12;
	pw[0] = 1; pw[1] = 3; pw[2] = 9;
	for(int i = 3; i < maxn; i++) {
		pw[i] = pw[i-1] * 3 % p;
		a[i] = (3 * a[i-1] + a[i-2] - 3 * a[i-3] + pw[i]) % p;
	}
	while(t--) {
		n = Mker::rand();
		res ^= a[n]<0?(a[n]%p+p)%p:a[n];
	}
	printf("%lld\n", res);
}
