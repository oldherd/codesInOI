#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 2010;
int pls[maxn][2], a[maxn], b[maxn], au = 1, n;

inline void unq() {
	for(int i = 1; i <= n; i++)
		if(a[i] != a[i-1])
			a[au++] = a[i];
}

inline int bound(int x) {
	int l = 0, r = au-1, mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(a[mid] <= x) l = mid;
		else r = mid-1;
	}
	return l;
}

int main() {
	int id;
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], b[i] = a[i];
	sort(a+1, a+n+1);
	unq();
	for(int i = 1; i <= n; i++) {
		id = bound(b[i]);
		if(!pls[id][0]) pls[id][0] = i;
		pls[id][1] = i;
	}
	for(int i = 0; i < au; i++)
	return 0;
}
