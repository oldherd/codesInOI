#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-7;

int dcmp(double x) {
	return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);
}

struct pt {
	double x, y;
	pt(double X, double Y): x(X), y(Y) {}
};
typedef pt vec;

vec operator - (pt p1, pt p2) {
	return vec(p1.x - p2.x, p1.y - p2.y);
}

double cross(vec v1, vec v2) {
	return v1.x * v2.y - v1.y * v2.x;
}

struct line {
	pt p0;
	vec v;
	line(pt P0, vec V): p0(P0), v(V) {}
};

int main() {
	int t;
	scanf("%d", &t);
	printf("INTERSECTING LINES OUTPUT\n");
	while(t--) {
		double x1, y1, x2, y2;
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		line l1(pt(x1, y1), vec(x2 - x1, y2 - y1));
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		line l2(pt(x1, y1), vec(x2 - x1, y2 - y1));
		if(dcmp(cross(l1.v, l2.v)) == 0) {   //方向向量叉积为０
			//printf("%.9lf, %.2lf, %.2lf, %.2lf, %.2lf\n", cross(l1.p0 - l2.p0, l1.v), (l1.p0-l2.p0).x, (l1.p0-l2.p0).y, l1.v.x, l1.v.y);
			if(dcmp(cross(l1.p0 - l2.p0, l1.v)) == 0) {
				printf("LINE\n");
			} else {
				printf("NONE\n");
			}
		} else {
			double t1 = cross(l2.p0 - l1.p0, l2.v) / cross(l1.v, l2.v);
			printf("POINT %.2lf %.2lf\n", l1.p0.x + t1 * l1.v.x, l1.p0.y + t1 * l1.v.y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
