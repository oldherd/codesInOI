#include <cstdio>

using namespace std;

const int maxn = 100005, inf = 2147483647;

struct Splay{
	int tot, root;
	int size[maxn], cnt[maxn], val[maxn];
	int ch[maxn][2], fa[maxn];
	Splay() { tot = 1; root = 0; insert(-inf); insert(inf); }
	int newnode(int v, int f) {
		ch[tot][0] = ch[tot][1] = 0; val[tot] = v;
		cnt[tot] = size[tot] = 1; fa[tot] = f;
		return tot++;
	}
	int chr(int x) { return x == ch[fa[x]][1]; }
	void update(int x) { size[x] = size[ch[x][0]] + size[ch[x][1]] + cnt[x]; }
	void rotate(int x) {
		int y = fa[x], z = fa[y], k = chr(x), s = ch[x][k^1];
		ch[y][k] = s; fa[s] = y;
		ch[z][chr(y)] = x; fa[x] = z;
		ch[x][k^1] = y; fa[y] = x;
		update(y); update(x);
	}
	void splay(int x, int goal = 0) {
		while(fa[x] != goal) {
			if(fa[fa[x]] != goal) rotate(chr(x)==chr(fa[x])?fa[x]:x);
			rotate(x);
		}
		if(!goal) root = x;
	}
	void find(int v) {
		int cur = root;
		while(ch[cur][v>val[cur]] && v != val[cur]) cur = ch[cur][v>val[cur]];
		splay(cur);
	}
	void insert(int v) {
		int cur = root;
		while(ch[cur][v>val[cur]] && v != val[cur]) cur = ch[cur][v>val[cur]];
		if(val[cur] == v)
			cnt[cur]++;
		else
			cur = ch[cur][v>val[cur]] = newnode(v, cur);
		splay(cur);
	}
	int prePost(int v, int f) {
		find(v);
		if((v>val[root] && !f) || (v<val[root] && f)) return root;
		int cur = ch[root][f]; f ^= 1;
		while(ch[cur][f]) cur = ch[cur][f];
		return cur;
	}
	void erase(int v) {
		int pre = prePost(v, 0), post = prePost(v, 1);
		splay(pre); splay(post, pre);
		int del = ch[post][0];
		if(cnt[del] > 1) {
			cnt[del]--; splay(del);	
		} else {
			ch[post][0] = 0; update(post); update(pre);
		}
	}
	int rank(int v) {
		find(v);
		return size[ch[root][0]] + (val[root]<v?cnt[root]:0);	
	}
	int parti(int cur, int k) {
		if(size[ch[cur][0]]+cnt[cur] >= k && size[ch[cur][0]] < k) return val[cur];
		if(size[ch[cur][0]] >= k) return parti(ch[cur][0], k);
		return parti(ch[cur][1], k-cnt[cur]-size[ch[cur][0]]);
	}
	int kth(int k) {
		if(tot-3 < k) return -inf-1;
		return parti(root, k+1);
	}
}s;

int main() {
	int n, opt, x;
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d", &opt, &x);
		if(opt == 1) s.insert(x);
		else if(opt == 2) s.erase(x);
		else if(opt == 3) printf("%d\n", s.rank(x));
		else if(opt == 4) printf("%d\n", s.kth(x));
		else if(opt == 5) printf("%d\n", s.val[s.prePost(x, 0)]);
		else printf("%d\n", s.val[s.prePost(x, 1)]);
	}
	return 0;
}
