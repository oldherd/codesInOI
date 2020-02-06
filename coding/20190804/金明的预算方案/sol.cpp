#include <cstdio>
#include <iostream>

using namespace std;

const int maxm = 70, maxn = 32010, inf = 0x3f3f3f3f;

inline int max(int x, int y) { return x > y ? x : y; }

class pii{
public:
	pii() {}
	pii(int V, int W) : v(V), w(W) {}
	int v, w;
};

class Item{
friend ostream& operator << (ostream&, Item&);
public:	
	Item() { num = 0; }
	pii f1() { return pii(vm, wm); }
	pii f2() { return pii(vm+v1, wm+w1); }
	pii f3() { return pii(vm+v2, vm+w2); }
	pii f4() { return pii(vm+v1+v2, wm+w1+w2); }
	bool is2() { return num > 1; }
	bool is3() { return num > 2; }
	void append(int v, int w);
	~Item() {}
private:
	int vm, wm;
	int v1, w1;
	int v2, w2;
	int num;
}item[maxn];

void Item::append(int v, int w) {
	switch(num) {
		case 0: vm = v; wm = w; break;
		case 1: v1 = v; w1 = w; break;
		case 2: v2 = v; w2 = w; break;
	}
	num++;
}

int n, m, endItem;
int f[maxn], hs[maxn];

inline int get(int j, pii it) {
	if(j < it.v) return -inf;
	return f[j-it.v] + it.w;
}

int main() {
	int v, p, mn, ans = -inf;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d", &v, &p, &mn);
		if(!mn) {
			hs[i] = endItem;
			item[endItem++].append(v, v*p);
		} else {
			item[hs[mn]].append(v, v*p);	
		}
	}
	f[0] = 0; for(int i = 1; i < maxn; i++) f[i] = -inf;
	for(int i = 0; i < endItem; i++)
		for(int j = n; j > -1; --j) {
			int rs = get(j, item[i].f1());
			if(item[i].is2()) rs = max(rs, get(j, item[i].f2()));
			if(item[i].is3()) {
				rs = max(rs, get(j, item[i].f3()));
				rs = max(rs, get(j, item[i].f4()));
			}
			ans = max(rs, ans);
			f[j] = max(f[j], rs);
		}
	printf("%d\n", ans);
	return 0;
}
