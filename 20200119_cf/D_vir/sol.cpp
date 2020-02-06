#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

inline ll getdis(ll x1, ll y1, ll x2, ll y2) { return abs(y2 - y1) + abs(x2 - x1); }

ll ax, ay, bx, by;
inline ll prex(ll xi) { return (xi - bx) / ax; }
inline ll nexx(ll xi) { return xi * ax + bx; }
inline ll prey(ll yi) { return (yi - by) / ay; }
inline ll nexy(ll yi) { return yi * ay + by; }
vector<ll> vx, vy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x0, y0, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    ll xi = x0, yi = y0;
    while(xi < 3e16 && yi < 3e16) {
        if(getdis(xi, yi, xs, ys) <= t) {
            vx.push_back(xi);
            vy.push_back(yi);
        }
        xi = nexx(xi);
        yi = nexy(yi);
        if(xi < 0 || yi < 0) break;
    }
//    cout << vx.size() << endl;
//    for(int i = 0; i < vx.size(); ++i) cout << vx[i] << ' ' << vy[i] << '\n';
    ll tt;
    int ans = 0;
    for(int i = 0; i < vx.size(); ++i) { // start place
        for(int l = 0; l < vx.size(); ++l) { // left side
            for(int r = l; r < vx.size(); ++r) { //right side
//            	if(l == 0 && i == 1 && r == 2) {
//            		int tmp = 0;
//            		tmp = 0;
//            	}
                if(l <= i && i <= r) {
                    tt = getdis(vx[i], vy[i], xs, ys) + getdis(vx[l], vy[l], vx[r], vy[r]) + min(getdis(vx[l], vy[l], vx[i], vy[i]), getdis(vx[r], vy[r], vx[i], vy[i]));
//                    cout << l << ' ' << i << ' ' << r << ' '  << tt << ' ' << ans << '\n'; 
                    if(tt <= t) {
                        ans = max(ans, r - l + 1);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
