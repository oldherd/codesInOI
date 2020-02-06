#include <cstdio>
#include <vector>
#include <algorithm>
#define itra vector<Block>::iterator
#define ritra vector<Block>::reverse_iterator

using namespace std;

const int N = 123456, INF = 0x3f3f3f3f;

struct Block{
	int l, r;
	Block();
	Block(int L, int R) :l(L), r(R) {}
	bool operator < (const Block &o) const { 
		return l == o.l ? r < o.r : l < o.l;
	}
};
vector<Block> vb, vt;
int vend;

int c[N], ifp[N], ibp[N], yl[N], up = 1;
int pre[N], sub[N];

int bound1(int l, int r, int key) {
	int mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(vt[mid].r < key) l = key;
		else r = key - 1;
	}
	return l;
}

int bound2(int l, int r, int key) {
	int mid;
	while(l < r) {
		mid = (l + r) >> 1;
		if(vt[mid].l > key) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	int n, m, k, a, b, w;
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		if(w) { vb.push_back(Block(a, b)); }
		else {
			++c[a]; --c[b + 1];
		}
	}
	for(int i = 1; i <= n; ++i) {
		c[i] += c[i - 1];
		if(!c[i]) {
			yl[up] = i; ifp[i] = ibp[i] = up++;
		} else ifp[i] = up - 1, ibp[i] = up;
	}
	sort(vb.begin(), vb.end());
	int rmin = INF;
	for(itra it = vb.begin(); it != vb.end(); ++it) {
		it->l = ibp[it->l]; it->r = ifp[it->r];
	}
	for(ritra it = vb.rbegin(); it != vb.rend(); ++it) {
//		printf("(%d, %d) ", it->l, it->r);
		if(it -> r < rmin)
			vt.push_back(Block(it->l, it->r));
		rmin = min(rmin, it -> r); 
	}	
//	printf("\n");
//	for(int i = 1; i <= n; ++i) printf("%d ", ifp[i]);
//	printf("\n");
//	for(int i = 1; i <= n; ++i) printf("%d ", ibp[i]);
//	printf("\n");
//	for(int i = 0; i < vt.size(); ++i) printf("(%d,%d) ", yl[vt[i].l], yl[vt[i].r]);
//	printf("#%llu\n", vt.size());
	if(up - 1 < k) {
		printf("-1\n");
		return 0;
	}
	 else if(up - 1 == k) {
		for(int i = 1; i < up; ++i) printf("%d\n", yl[i]);
		printf("\n");
		return 0;
	}
	reverse(vt.begin(), vt.end());
	vend = vt.size();
	int cover = 0, cnt = 0;
	for(int i = 0; i < vend; ++i) {
		if(vt[i].l > cover) {
			++cnt; cover = vt[i].r;
		}
		pre[i] = cnt;
	}
	cover = INF; cnt = 0;
	for(int i = vend - 1; ~i; --i) {
		if(vt[i].r < cover) {
			++cnt; cover = vt[i].l;
		}
		sub[i] = cnt;
	}
	bool flag = true;
	for(int i = 0; i < vend; ++i) {
		if(vt[i].l == vt[i].r) {
			printf("%d\n", yl[vt[i].l]);
			flag = false;
			continue;
		}
		int pls = vt[i].r - 1;
		int tl = bound1(0, vend - 1, pls), tr = bound2(0, vend - 1, pls);
		if(!tl && vt[0].r >= pls) tl = n + 1;
		if(tr == vend - 1 && vt[vend - 1].l <= pls) tr = n + 1;
		if(pre[tl] + sub[tr] + 1 > k) {
			printf("%d\n", yl[vt[i].r]);
			flag = false;
		}
	}
	if(flag) printf("-1\n");
	return 0;
}
