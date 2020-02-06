#include <iostream>

using namespace std;

int p;

int gcd(int a,int b) {while(b^=a^=b^=a%=b);return a;}

//inline int qpow(int a, int b) {
//	int res = 1 % p;
//	for(;b;b>>=1) {
//		if(b&1) res = (long long)res * a % p;
//		a = (long long)a * a % p;
//	}
//	return res;
//}

long long qpow(long long a,long long b)
{
	long long ans = 1 % p;
	for(;b;b>>=1) {
		if(b & 1)ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}

int main() {
	int t, a, b, c;
	long long res1, res2, res3;
	scanf("%d %d", &t, &p);
	while(t--) {
		scanf("%d %d %d", &a, &b, &c);
		res1 = res2 = res3 = 1;
		for(int i = 1; i <= a; i++)
			for(int j = 1; j <= b; j++)
				for(int k = 1; k <= c; k++) {
					int g1 = gcd(i, j), g2 = gcd(i, k), g3 = gcd(g1, g2);
					 long long tt = ((long long)i * j / g1 / g2) % p;
					 if(t == 0) {
					 	printf("%d %d %d %lld\n", i, j, k, tt);
					 }
					 res1 *= tt;
					 res2 *= qpow(tt, i*j*k);
					 res3 *= qpow(tt, g3);
				}
		printf("%lld %lld %lld\n", res1, res2, res3);
	}
	return 0;	
}
