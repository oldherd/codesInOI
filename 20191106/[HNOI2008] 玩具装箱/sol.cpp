#include <cstdio>
#include <cassert>
#include <queue> 
#define ll long long

using namespace std;

struct node{
	int l, r, x;
	node() {}
	node(int L, int R, int X) : l(L), r(R), x(X) {}
};
deque<node> sta;
const int N = 56789;
ll f[N], s[N], l;

inline ll getw(int x, int y) { return (y-x+s[y]-s[x-1]-l) * (y-x+s[y]-s[x-1]-l);}
inline bool ckupd(int x, int y, int t) {
	return f[x] + getw(x + 1, t) < f[y] + getw(y + 1, t);
}
 
int main() {
	int n;
	scanf("%d %lld", &n, &l);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", s + i);
		s[i] += s[i-1];
	}
	sta.push_back(node(1, n, 0));
	for(int i = 1; i <= n; ++i) {
		while(sta.front().r < i) sta.pop_front();
		f[i] = f[sta.front().x] + getw(sta.front().x+1, i);
		while(!sta.empty()) {
			if(ckupd(i, sta.back().x, sta.back().l)) sta.pop_back();
			else break;
		}
		if(sta.empty()) {
			sta.push_back(node(i+1, n, i));
		} else if(ckupd(i,sta.back().x,sta.back().r)) {
			node tmp = sta.back();
			int l = tmp.l+1, r = tmp.r;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(ckupd(i, tmp.x, mid)) r = mid;
				else l = mid + 1;
			}
			sta.pop_back();
			sta.push_back(node(tmp.l, l-1, tmp.x));
			sta.push_back(node(l, n, i));
		} else {
			if(sta.back().r < n) sta.push_back(node(sta.back().r+1, n, i));
		}
	}
	printf("%lld\n", f[n]);
	return 0;
}
