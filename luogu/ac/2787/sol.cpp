#include <cstdio>
#include <queue> 

using namespace std;

const int sz = 3000000;

struct node{
	int ls, rs, val, laz;	
}t[sz];
int root[30], tot = 1;

inline int newnode() {
	t[tot].ls = t[tot].rs = t[tot].val = 0; t[tot].laz = -1;
	return tot++;	
}

inline void spread(int p, int ll, int rl) {
	if(!t[p].ls) t[p].ls = newnode();
	if(!t[p].rs) t[p].rs = newnode();
	if(t[p].laz == -1) return;
	t[t[p].ls].val = ll * t[p].laz; t[t[p].rs].val = rl * t[p].laz;
	t[t[p].ls].laz = t[p].laz; t[t[p].rs].laz = t[p].laz;
	t[p].laz = -1;
}

inline void change(int p, int lp, int rp, int l, int r, int v) {
	if(l <= lp && rp <= r) { t[p].val = (rp - lp + 1) * v; t[p].laz = v; return; }
	int mid = (lp + rp) >> 1;
	spread(p, mid-lp+1, rp-mid);
	if(l <= mid) change(t[p].ls, lp, mid, l, r, v);
	if(r > mid) change(t[p].rs, mid+1, rp, l, r, v);
	t[p].val = t[t[p].ls].val + t[t[p].rs].val;
}

inline int query(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return t[p].val;
	int mid = (lp + rp) >> 1;
	spread(p, mid-lp+1, rp-mid);
	int ans = 0;
	if(l <= mid) ans = query(t[p].ls, lp, mid, l, r);
	if(r > mid) ans += query(t[p].rs, mid+1, rp, l, r);
	return ans;
}

inline int getc() {
	char ch;
	do{
		ch = getchar();
	}while((ch < 'A' || ch > 'Z') && (ch < 'a' || ch > 'z'));
	return ch > 'Z' ? ch - 'a' : ch - 'A';
}

int main() {
	int n, m, op, t, g, c;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < 26; i++) root[i] = newnode();
	for(int i = 1; i <= n; i++) change(root[getc()], 1, n, i, i, 1);
	while(m--) {
		scanf("%d %d %d", &op, &t, &g);
		if(op != 3) c = getc();
		if(op == 1) {
			printf("%d\n", query(root[c], 1, n, t, g));
		} else if(op == 2) {
			for(int i = 0; i < 26; i++)
				if(i == c) change(root[i], 1, n, t, g, 1);
				else change(root[i], 1, n, t, g, 0);
		} else {
			int p = 0, tt;
			for(int i = 0; i < 26; i++) {
				tt = query(root[i], 1, n, t, g);
				if(!tt) continue;
				change(root[i], 1, n, t, g, 0);
				change(root[i], 1, n, t+p, t+p+tt-1, 1);
				p += tt;
			}
		}
	}
	return 0;	
}
