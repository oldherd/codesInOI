#include <cstdio>
#include <cmath>

using namespace std;

namespace Mker
{
	#define uint unsigned int
	uint sd;int op;
	inline void init() {scanf("%u %d", &sd, &op);}
	inline uint uint_rand()
	{
		sd ^= sd << 13;
		sd ^= sd >> 7;
		sd ^= sd << 11;
		return sd;
	}
	inline double get_n()
	{
		double x = (double) (uint_rand() % 100000) / 100000;
		return x + 4;
	}
	inline double get_k()
	{
		double x = (double) (uint_rand() % 100000) / 100000;
		return (x + 1) * 5;
	}
	inline void read(double &n,double &a, double &b)
	{
		n = get_n(); a = get_k();
		if (op) b = a;
		else b = get_k(); 
	}
}

int main() {
	int t;
	double n, a, b, ans = 0;
	scanf("%d", &t);
	Mker::init();
	while(t--) {
		Mker::read(n, a, b);
		if(Mker::op == 0) {
			double th = pow(n, a) + pow(n, b);
			int tt = (int)th;
			double l = n-1, r = n, mid, amin, amax;
			for(int i = 1; i <= 23; i++) {
				mid = (l + r) / 2;
				if((int)(pow(mid, a)+pow(mid, b)) == tt) r = mid;
				else l = mid;
			}
			amin = l;
			l = n; r = n+1;
			for(int i = 1; i <= 23; i++) {
				mid = (l + r) / 2;
				if((int)(pow(mid, a)+pow(mid, b)) == tt) l = mid;
				else r = mid;
			}
			amax = l;
			ans += amax - amin;
		} else {
			double th = pow(n, a)*2;
			int tt = (int)th;
			double l = n-1, r = n, mid, amin, amax;
			for(int i = 1; i <= 26; i++) {
				mid = (l + r) / 2;
				if((int)(pow(mid, a)*2) == tt) r = mid;
				else l = mid;
			}
			amin = l;
			l = n; r = n+1;
			for(int i = 1; i <= 26; i++) {
				mid = (l + r) / 2;
				if((int)(pow(mid, a)*2) == tt) l = mid;
				else r = mid;
			}
			amax = l;
			ans += amax - amin;
		}
	}
	printf("%lf\n", ans);
	return 0;	
}
