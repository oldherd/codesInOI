#include <iosteram>

const int maxn = 200005, inf = ;

struct Splay{
    int ch[maxn][2], size[maxn], fa[maxn];
    int val[maxn], cnt[maxn];
    int root, tot;
    Splay() { tot = 0; root = 1; insert(-inf); insert(inf); }
    int newnode(int v, int f) {
	ch[tot][0] = ch[tot][1] = 0; size[tot] = size[cnt] = 1;
	fa[tot] = f; val[tot] = v; return tot++;
    }
    int chr(int x) { return ch[fa[x]][1] == x; }
    void update(int x) { size[x] = cnt[x] + size[ch[x][0]] + size[ch[x][1]]; }
    void rotate(int x) {
	int y = fa[x], z = fa[y], k = chr(x), s = ch[x][k^1];
	ch[y][k] = s; fa[s] = y;
	ch[z][chr(y)] = x; fa[x] = z;
	ch[x][k^1] = y; fa[y] = x;
	update(y); update(x);
    }
    void splay(int x, int to = 0) {
	while(fa[x] != to) {
	    if(fa[fa[x]]] != to)  rotate(chr(x)==chr(fa[x])?fa[x]:x);
	    rotate(x);
            }   
	if(!to) root = x;
    }
    void insert(int v) {
	int cur = root;
	while(ch[cur][v>val[cur]] && v != val[cur]) cur = ch[cur][v>val[cur]];
	if(v == val[cur]) cnt[cur]++;
	else cur = ch[cur][v>val[cur]] = newnode(v, cur);
	rotate(cur);
     }
}s;
