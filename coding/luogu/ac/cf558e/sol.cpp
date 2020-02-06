#include <cstdio>

using namespace std;

const int sz = 7000010, maxn = 100010;

inline void read(int &x) {
	char ch = getchar();
	x = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = getchar();	
}

struct stree{
	int ls, rs, val, laz;
}t[sz];
int root[30], tot = 1;

inline int newnode() {
	t[tot].ls = t[tot].rs = t[tot].val = 0; t[tot].laz = -1;
	return tot++;
}

inline void spread(int p, int ll, int lr) {
	if(!t[p].ls) t[p].ls = newnode();
	if(!t[p].rs) t[p].rs = newnode();
	if(t[p].laz == -1) return;
	t[t[p].ls].val = ll * t[p].laz; t[t[p].ls].laz = t[p].laz;
	t[t[p].rs].val = lr * t[p].laz; t[t[p].rs].laz = t[p].laz;
	t[p].laz = -1;
}

inline void change(int p, int lp, int rp, int l, int r, int v) {
	if(l <= lp && rp <= r) { t[p].val = (rp-lp+1) * v; t[p].laz = v; return; }
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
	if(l <= mid) ans += query(t[p].ls, lp, mid, l, r);
	if(r > mid) ans += query(t[p].rs, mid+1, rp, l, r);
	return ans;
}

char s[maxn];

inline void putree(int p, int lp, int rp, char ch) {
	if(t[p].val == rp-lp+1)	{
		for(int i = lp; i <= rp; i++) s[i] = ch;
		return;	
	}
	if(lp == rp) return;
	int mid = (lp + rp) >> 1;
	spread(p, mid-lp+1, rp-mid);
	if(t[p].ls && t[t[p].ls].val) putree(t[p].ls, lp, mid, ch);
	if(t[p].rs && t[t[p].rs].val) putree(t[p].rs, mid+1, rp, ch);
}

int main() {
	int n, m, t, g, c;
	char ch;
	read(n); read(m);
	for(int i = 0; i < 26; i++) root[i] = newnode();
	for(int i = 1; i <= n; i++) {
		do{
			ch = getchar();
		}while(ch < 'a' || ch > 'z');
		change(root[ch-'a'], 1, n, i, i, 1);
	}
	while(m--) {
		read(t); read(g); read(c);
		int p = 0, tt;
		if(c == 1) {
			for(int i = 0; i < 26; i++) {
				tt = query(root[i], 1, n, t, g);
				if(!tt) continue;
				change(root[i], 1, n, t, g, 0);
				change(root[i], 1, n, t+p, t+p+tt-1, 1);
				p += tt;
			}
		} else {
			for(int i = 25; i > -1; --i) {
				tt = query(root[i], 1, n, t, g);
				if(!tt) continue;
				change(root[i], 1, n, t, g, 0);
				change(root[i], 1, n, t+p, t+p+tt-1, 1);
				p += tt;
			}
		}
	}
	for(int i = 0; i < 26; i++) 
		putree(root[i], 1, n, 'a'+i);
	for(int i = 1; i <= n; i++) putchar(s[i]);
	return 0;	
}
