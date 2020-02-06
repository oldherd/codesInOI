#include <iostream>
#include <cstdio>

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

const double eps = 1e-5;
struct three {
	double a, b, c;
	three(double A, double B, double C) : a(A), b(B), c(C) {}
	three() {};
	bool operator == (const three& o) const {
		return a - o.a  < eps && b - o.b < eps && c - o.c < eps;
	}
	bool operator != (const three &o) const {
		return !((*this) == o);	
	}
};
three ai[5500000];

using namespace Mker;

int main() {
	double n, a, b;
	init();
	for(int i = 0; i <= 10000000; i++) {
		read(n, a, b);
		three t(n, a, b);
		ai[i] = t;
		if(ai[i%4999950] == ai[i]) continue;
		cerr << "Error" << i << endl;
		return 0;
	}
	cout << "fine" << endl;
	return 0;	
}
