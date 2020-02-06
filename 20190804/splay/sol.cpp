#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 200010, inf = 2147483647;

struct Splay{
	int tot, root;
	int val[maxn], size[maxn], cnt[maxn];
	int ch[maxn][2], fa[maxn];
	Splay() { 
		tot = 1; root = 0; insert(-inf); insert(inf);
		ch[0][0] = ch[0][1] = fa[0] = 0;
	}
	int newnode(int value, int father) {
		val[tot] = value; size[tot] = cnt[tot] = 1;
		ch[tot][0] = ch[tot][1] = 0; fa[tot] = father;
		return tot++;
	}
	int chr(int p) { return ch[fa[p]][1] == p; }
	void pushup(int p) { size[p] = size[ch[p][0]] + size[ch[p][1]] + cnt[p]; }
	void rotate(int x) {
		int y = fa[x], z = fa[y], k = chr(x), s = ch[x][k^1];
		ch[y][k] = s; fa[s] = y;
		ch[z][chr(y)] = x; fa[x] = z;
		ch[x][k^1] = y; fa[y] = x;
		pushup(y); pushup(x); 
	}
	void splay(int x, int goal = 0) {
		while(fa[x] != goal) {
			if(fa[fa[x]] != goal) rotate(chr(x)==chr(fa[x]) ? fa[x] : x);
			rotate(x);
		}
		if(!goal) root = x;
	}
	void find(int v) {
		int cur = root;
		while(ch[cur][v>val[cur]] && v != val[cur]) cur = ch[cur][v>val[cur]];
		splay(cur);
	}
	int prePost(int v, int f) {
		find(v);
		if((val[root]<v && !f) || (val[root]>v && f)) return root;
		int cur = ch[root][f]; f ^= 1;
		while(ch[cur][f]) cur = ch[cur][f];
		return cur;
	}
	void insert(int v) {
		int cur = root;
		while(ch[cur][v>val[cur]] && v != val[cur]) cur = ch[cur][v>val[cur]];
		if(v == val[cur])
			cnt[cur]++;
		else
			cur = ch[cur][v>val[cur]] = newnode(v, cur);
		splay(cur);			//因为cur的改变所以以上部分都要变,为了避免所以splay到根
	}
	void erase(int v) {
		int pre = prePost(v, 0), post = prePost(v, 1);
		splay(pre); splay(post, pre);
		int del = ch[post][0];
		if(cnt[del] > 1) {
			cnt[del]--;
			splay(del);
		} else {
			ch[post][0] = 0;
			pushup(post); pushup(pre);
		}
	}
	int rank(int v) {
		find(v);
		return size[ch[root][0]] + (v>val[root]?cnt[root]:0);
	}
	int kth(int k) {
		if(k > tot-3) return -inf;
		return parti(root, k+1);
	}
	int parti(int x, int k) {
		if(size[ch[x][0]]+cnt[x]>=k && size[ch[x][0]]<k) return val[x];
		if(size[ch[x][0]] >= k) return parti(ch[x][0], k);
		return parti(ch[x][1], k-size[ch[x][0]]-cnt[x]);
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
