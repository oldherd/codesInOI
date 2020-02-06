#include <cstdio>
#include <cmath>
#include <iostream>

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

const double eps = 1e-7;
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
three ai[10000010];

using namespace Mker;

int main() {
	double n, a, b;
	init();
	for(int i = 0; i < 10000000; i++) {
		read(n, a, b);
		ai[i] = three(n, a, b);
	}
	for(int i = 1; i <= 10000000; i++) {
		bool flag = true;
		for(int j = i; j < 10000000; j++)
			if(ai[j%i] != ai[j]) {
				flag = false;
				break;
			}
		if(flag) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;	
}
