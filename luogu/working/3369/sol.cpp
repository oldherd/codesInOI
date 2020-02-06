#include <cstdio>

using namespace std;

const int ad = 1e7+1, inf = -1e7, sz = 7000010;

struct stree{
	int ls, rs, val;
}t[sz];
int root, tot = 1, start = 1, end = 1e7 + ad;

inline int newnode() {
	t[tot].ls = t[tot].rs = t[tot].val = 0;
	return tot++;
}

inline void insert(int p, int lp, int rp, int x) {
	if(lp == rp) { t[p].val++; return; }
	int mid = (lp + rp) >> 1;
	if(x <= mid) {
		if(!t[p].ls) t[p].ls = newnode();
		insert(t[p].ls, lp, mid, x);	
	} else {
		if(!t[p].rs) t[p].rs = newnode();
		insert(t[p].rs, mid+1, rp, x);	
	}
	t[p].val++;
}

inline void del(int p, int lp, int rp, int x) {
	if(lp == rp) { t[p].val--; return; }
	int mid = (lp + rp) >> 1;
	if(x <= mid) {
		if(!t[p].ls) t[p].ls = newnode();
		del(t[p].ls, lp, mid, x);	
	} else {
		if(!t[p].rs) t[p].rs = newnode();
		del(t[p].rs, mid+1, rp, x);	
	}
	t[p].val--;
}

inline int kth(int p, int lp, int rp, int k) {
	if(lp == rp) return lp;
	int mid = (lp + rp) >> 1;
	if(t[t[p].ls].val >= k) return kth(t[p].ls, lp, mid, k);
	return kth(t[p].rs, mid+1, rp, k-t[t[p].ls].val);
}

inline bool query(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return t[p].val != 0;
	int mid = (lp + rp) >> 1;
	bool ans = false;
	if(l <= mid) ans |= query(t[p].ls, lp, mid, l, r);
	if(r > mid) ans |= query(t[p].rs, mid+1, rp, l, r);
	return ans;
}

inline int qu(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return t[p].val;
	int mid = (lp + rp) >> 1;
	int ans = 0;
	if(l <= mid) ans += qu(t[p].ls, lp, mid, l, r);
	if(r > mid) ans += qu(t[p].rs, mid+1, rp, l, r);
	return ans;
} 

inline int ahead(int p, int lp, int rp, int x) {
	if(lp == rp) return lp;
	int mid = (lp + rp) >> 1;
	if(mid >= x) return ahead(t[p].ls, lp, mid, x);
	if(query(root, start, end, mid, x-1)) return ahead(t[p].rs, mid+1, rp, x);
	return ahead(t[p].ls, lp, mid, x); 
}

inline int next(int p, int lp, int rp, int x) {
	if(lp == rp) return lp;
	int mid = (rp+lp) >> 1;
	if(mid <= x) return next(t[p].rs, mid+1, rp, x);
	if(query(root, start, end, x+1, mid)) return next(t[p].ls, lp, mid, x);
	return next(t[p].rs, mid+1, rp, x);
}

void pqry(int l, int r) {
	printf("######################%d\n", qu(root, start, end, l, r));	
}

int main() {
	root = newnode();
	int m, opt, x;
	scanf("%d", &m);
	while(m--) {
		scanf("%d %d", &opt, &x);
		if(opt == 1) insert(root, start, end, x);
		else if(opt == 2) del(root, start, end, x);
		else if(opt == 3) printf("%d\n", x == inf ? 1 : qu(1, start, end, start, x-1) + 1);
		else if(opt == 4) printf("%d\n", kth(1, start, end, x));
		else if(opt == 5) 
			printf("%d\n", ahead(1, start, end, x));
		else if(opt == 6) printf("%d\n", next(1, start, end, x)); 
		else printf("%d\n", qu(1, start, end, x, x));
	}
	return 0;
}
