#include <cstdio>
#include <cmath>

const double pi = acos(-1), eps = 1e-8;

struct pt {
	double x, y;
	pt() {}
	pt(double X, double Y): x(X), y(Y) {}
	bool operator < (const pt& o) const { return x < o.x || x == o.x && x < o.y; }
	double operator * (const pt& o) const { return x * o.y - y * o.x; }
	pt operator - (const pt& o) const { return pt(x-o.x, y-o.y); }
};

double dot(const pt lhs, const pt rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

inline pt rotate(pt o, double xita) {
	return pt(o.x * cos(xita) - o.y * sin(xita), o.y * cos(xita) + o.x * sin(xita));
}

inline double len(pt o) {
	return sqrt(o.x * o.x + o.y * o.y);
}

inline bool meet(pt a, pt b, pt c, pt d) {
	return ((b-a)*(c-a)) * ((b-a)*(d-a)) < 0 && ((d-c)*(b-c)) * ((d-c)*(a-c)) < 0;
}

pt point[10];

int main() {
	double x, y;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lf %lf", &x, &y);
		point[i] = rotate(pt(x + eps, y + eps), eps);
	}
	printf("%lf\n", dot(point[1], point[2]));
	printf("%lf\n", acos(dot(point[1], point[2]) / len(point[1]) / len(point[2])));
	printf("%d\n", meet(point[1], point[2], point[3], point[4]));
	return 0;
}
