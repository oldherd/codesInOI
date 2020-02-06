#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

ll ax, ay, bx, by;

ll getdis(ll x1, ll y1, ll x2, ll y2) {
	return abs(y1 - y2) + abs(x1 - x2);
}

inline ll prex(ll xi) {
	return (xi - bx) / ax;
}

inline ll nexx(ll xi) {
	return xi * ax + bx;
}

inline ll prey(ll yi) {
	return (yi - by) / ay;
}

inline ll nexy(ll yi) {
	return yi * ay + by;
}

int main() {
	ll x0, y0, xs, ys, t;
	scanf("%lld %lld %lld %lld %lld %lld", &x0, &y0, &ax, &ay, &bx, &by);
	scanf("%lld %lld %lld", &xs, &ys, &t);
	ll xl = x0, yl = x0, dis = getdis(xs, ys, xl, yl);
//	while(xl < 300) {
//		printf("%lld %lld\n", xl, yl);
//		xl = nexx(xl);
//		yl = nexy(yl);
//	}
	xl = x0, yl = y0;
	for(int i = 1; i <= 100 && xl < 3e16 && yl < 3e16; ++i) {
		if(dis > getdis(xs, ys, nexx(xl), nexy(yl))) {
			xl = nexx(xl);
			yl = nexy(yl);
		}
	}
	if(getdis(xs, ys, xl, yl) > t) {
		printf("0\n");
		return 0;
	}
	t -= getdis(xs, ys, xl, yl);
	ll ans = 1;
//	cout << t << ' ' << ans << '\n';
//	cout << xl << ' ' << yl << '\n';
	ll xi = xl, yi = yl;
	while(xi >= x0 && yi >= y0) {
		if(xi == x0 && yi == y0) break;
		if(getdis(xi, yi, prex(xi), prey(yi)) <= t) {
			t -= getdis(xi, yi, prex(xi), prey(yi));
			xi = prex(xi);
			yi = prey(yi);
			++ans;
		} else break;
	}
	if(getdis(xi, yi, xl, yl) <= t) {
		t -= getdis(xi, yi, xl, yl);
		xi = xl; yi = yl;
	} else {
		printf("%lld\n", ans);
		return 0;
	}
	while(getdis(xi, yi, nexx(xi), nexy(yi)) <= t) {
		t -= getdis(xi, yi, nexx(xi), nexy(yi));
		xi = nexx(xi);
		yi = nexy(yi);
		++ans;
	}
	printf("%lld\n", ans);
	return 0;
}
