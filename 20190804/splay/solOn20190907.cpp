#include <iostream>

using namespace std;

const int inf = 2147483647, maxn = 200005;

struct Splay{
	int fa[maxn], ch[maxn][2], size[maxn];
	int val[maxn], cnt[maxn];
	int root, tot;
	Splay() { 
		root = 0; tot = 1; 
		insert(-inf); 
		insert(inf); 
		}
	int newnode(int v, int f) {
		val[tot] = v; fa[tot] = f; size[tot] = cnt[tot] = 1;
		ch[tot][0] = ch[tot][1] = 0; return tot++;
	}
	int chr(int x) { return ch[fa[x]][1] == x; }
	int update(int x) { return size[x] = cnt[x] + size[ch[x][1]] + size[ch[x][0]]; }
	void rotate(int x) {
		int y = fa[x], z = fa[y], k = chr(x), s = ch[x][k^1];
		ch[y][k] = s; fa[s] = y;
		ch[z][chr(y)] = x; fa[x] = z;
		ch[x][k^1] = y; fa[y] = x;
		update(y); update(x);
	}
	void splay(int x, int to = 0) {
		while(fa[x] != to) {
			if(fa[fa[x]] != to) rotate(chr(x)==chr(fa[x])?fa[x]:x);
			rotate(x);
		}
		if(!to) root = x;
	}
	void insert(int v) {
		int cur = root;
		while(ch[cur][v>val[cur]] && v != val[cur]) cur = ch[cur][v>val[cur]];
		if(v == val[cur]) cnt[cur]++;
		else cur = ch[cur][v>val[cur]] = newnode(v, cur);
		splay(cur);
	}
	void find(int v) {		//if exists v than splay(v) else splay(rand(pre|post))
		int cur = root;
		while(ch[cur][v>val[cur]] && v != val[cur]) cur = ch[cur][v>val[cur]];
		splay(cur);
	}
	int prePost(int v, int f) {
		find(v);
		if((val[root]<v&&!f) || (val[root]>v&&f)) return root;
		int cur = ch[root][f]; f ^= 1;
		while(ch[cur][f]) cur = ch[cur][f];
		return cur;
	}
	void erase(int v) {
		int pre = prePost(v, 0);
		int post = prePost(v, 1);
		splay(pre); splay(post, pre);
		if(cnt[ch[post][0]] > 1) {
			cnt[ch[post][0]]--; splay(ch[post][0]);
		} else {
			ch[post][0] = 0; update(post); update(pre);
		}
	}
	int rank(int v) {
		find(v);
		return size[ch[root][0]] + (v>val[root]?cnt[root]:0);
	}
	int kth(int k) {
		if(k+3 > tot) return -inf-1;
		return parti(root, k+1);
	}
	int parti(int cur, int k) {
		if(size[ch[cur][0]]+cnt[cur] >= k && size[ch[cur][0]] < k) return val[cur];
		else if(size[ch[cur][0]] >= k) return parti(ch[cur][0], k);
		return parti(ch[cur][1], k-cnt[cur]-size[ch[cur][0]]);
	}
}s;

int main() {
	ios::sync_with_stdio(false);
	int n, op, v;
	cin >> n;
	while(n--) {
		cin >> op >> v;
		if(op == 1) s.insert(v);
		else if(op == 2) s.erase(v);
		else if(op == 3) cout << s.rank(v) << endl;
		else if(op == 4) cout << s.kth(v) << endl;
		else if(op == 5) cout << s.val[s.prePost(v, 0)] << endl;
		else cout << s.val[s.prePost(v, 1)] << endl;
	}
	return 0;
}
