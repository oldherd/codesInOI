#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-8;

struct point {
    double x, y;
    point(double X, double Y):x(X), y(Y) {}
    point() {}
};

typedef point vec;

vec operator + (const vec& v1, const vec& v2) {
    return vec(v1.x + v2.x, v1.y + v2.y);
}

vec operator - (const vec& v1, const vec& v2) {
    return vec(v1.x - v2.x, v1.y - v2.y);
}

vec operator * (const double& k, const vec& v) {
    return vec(v.x * k, v.y * k);
}

int dcmp(double x) {
    return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);
}

double cross(vec v1, vec v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

bool inli(point a, point b, point c) {
    return dcmp(cross(b - a, c - a)) == 0;
}

point ins(point a, point b, point c, point d) {
    return a + cross(c - a, d - a) / cross(b - a, d - c) * (b - a);
}

int main() {
    int t;
    printf("INTERSECTING LINES OUTPUT\n");
    scanf("%d", &t);
    while(t--) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        point a(x, y);
        scanf("%lf %lf", &x, &y);
        point b(x, y);
        scanf("%lf %lf", &x, &y);
        point c(x, y);
        scanf("%lf %lf", &x, &y);
        point d(x, y);
        if(dcmp(cross(b - a, d - c)) == 0) {
            if(inli(a, b, c)) {
                printf("LINE\n");
            } else {
                printf("NONE\n");
            }
        } else {
            point inser = ins(a, b, c, d);
            printf("POINT %.2f %.2f\n", inser.x, inser.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
