#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-8;

namespace Mker
{
//  Powered By Kawashiro_Nitori
//  Made In Gensokyo, Nihon
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
	double xi, xj, dx, ans = 0, n, a, b;
	int t, y;
	scanf("%d", &t);
	Mker::init();
	while(t--) {
		Mker::read(n, a, b);
		xi = n, xj = n;
		y = (int)(pow(xi, a) + pow(xi, b));
		do {
			dx = -(pow(xi, a)+pow(xi, b)-y) / (a*pow(xi,a-1)+b*pow(xi,b-1));
			xi += dx;	
		}while(dx > eps);
		do {
			dx = -(pow(xj, a)+pow(xj, b)-y-1) / (a*pow(xj,a-1)+b*pow(xj,b-1));
			xj += dx;
		}while(dx > eps);
		ans += xj - xi;
	}
	printf("%f\n", ans);
	return 0;	
}
