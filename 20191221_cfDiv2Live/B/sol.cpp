#include <cstdio>
#define ll long long

using namespace std;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, x, y), tmp = y;
    y = x - a / b * y; x = tmp;
    return gcd;
}

int main() {
    int n, m, tmp;
    ll s1 = 0, s2 = 0, x, y;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        s1 += tmp;
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        s2 += tmp;
    }
    ll dec = (s2 - s1 + m) % m;
    ll gcd = exgcd(m, n, x, y);
    x *= dec / gcd, y *= dec / gcd;
    y = (y % m + m) % m;
    //    printf("%lld %lld %lld %lld %lld\n", s2, s1, x, y, dec); 
    printf("%lld\n",y);
    return 0;
}
