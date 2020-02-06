#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 56789;
struct pt{
	int x, y;
	pt() {x = 0; y = 0;}
	pt(int X, int Y): x(X), y(Y) {}
	bool operator < (const pt&o) const {
		return x == o.x ? y > o.y : x < o.x;
	}
	pt operator = (const pt&o) {
		x = o.x; y = o.y; return *this;
	}
};
struct node{
	int l, r, x;
	node() {}
	node(int L, int R, int X): l(L), r(R), x(X) {}
};
deque<node> sta;
pt inp[N], p[N];
ll f[N];
int up = 1;

inline ll getW(int x, int y) { return (ll)p[x].y * p[y].x; }
inline bool ckupd(int x, int y, int t) { return f[x] + getW(x+1, t) < f[y] + getW(y+1, t); }

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &inp[i].x, &inp[i].y);
	sort(inp + 1, inp + n + 1);
	ll ht = 0;
	for(int i = n; i; --i) {
		if(inp[i].y > ht) {
			p[up++] = inp[i];
			ht = inp[i].y;
		}
	}
	reverse(p+1, p+up);
	f[0] = 0;
	sta.push_back(node(1, up-1, 0)); 
	for(int i = 1; i < up; ++i) {
		while(sta.front().r < i) sta.pop_front();
		f[i] = f[sta.front().x] + getW(sta.front().x+1, i);
		while(!sta.empty()) {
			if(ckupd(i, sta.back().x, sta.back().l)) sta.pop_back();
			else break;
		}
		if(sta.empty()) {
			sta.push_back(node(i+1, up-1, i));
		} else if(ckupd(i, sta.back().x, sta.back().r)) {
			node tmp = sta.back();
			sta.pop_back();
			int l = tmp.l+1, r = tmp.r, mid;
			while(l < r) {
				mid = (l + r) >> 1;
				if(ckupd(i, tmp.x, mid)) r = mid;
				else l = mid + 1;
			}
			sta.push_back(node(tmp.l, l-1, tmp.x));
			sta.push_back(node(l, up-1, i));
		} else {
			if(sta.back().r < up-1) sta.push_back(node(sta.back().r+1, up-1, i));
		}
	}
	printf("%lld\n", f[up-1]);
	return 0;
}
