#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000010, maxna = 50010, maxnb = 50010;

struct node{
    int w, v;	
    bool operator < (const node& o) const { return w < o.w; }
}toy[maxn];
int n, na, nb;

struct checker{
	private:		
		int ct[maxna], fa[maxna], data[maxna], n, sz;
		inline int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
		inline void merge(int x, int y) { x = get(x); y = get(y); fa[y] = x; }
		inline int upper_bound(int l, int r, int x) { 
			while(l < r) { int mid = (l + r) >> 1; if(data[mid] > x) r = mid; else l = mid + 1; }
			return l; 
		}
	public:
		inline void init(int t) {
			n = t; sz = sizeof(ct);
			for(int i = 1; i <= n; i++) scanf("%d", data+i);
			this->clear();
			sort(data+1, data+n+1);
		}
		inline void clear() { memset(ct, 0, sz); for(int i = 1; i < n+2; i++) fa[i] = i; }
		inline int bst() { return data[n]; }
		inline bool check(int xi, int t) {
			int pi = upper_bound(1, n, xi);
			if(data[pi] <= xi) return false;
			if((pi = get(pi)) == n+1) return false;
			if(++ct[pi] == t) merge(pi+1, pi);
			return true;
		} 
	
}c1, c2;

inline bool calc(int t) {
	c1.clear(); c2.clear();
    for(int i = n; i > 0; --i) {
        if(nb) if(c2.check(toy[i].v, t)) continue;
        if(na) { 
			if(!c1.check(toy[i].w, t)) return false;
		} else return false;
	}
	return true;
}

int main() {
    int tl, tr;
    scanf("%d %d %d", &n, &na, &nb);
    c1.init(na);
    c2.init(nb);
    for(int i = 1; i <= n; i++) scanf("%d %d", &toy[i].w, &toy[i].v);
    sort(toy+1, toy+n+1);
    for(int i = n; i > 0 && (!na || toy[i].w >= c1.bst()); --i)
        if(!nb || toy[i].v >= c2.bst())
            { printf("-1\n"); return 0; }
    tl = n / (na+nb); tr = n;
    while(tl < tr) {
        int mid = (tl + tr) >> 1;
        if(calc(mid)) tr = mid;
        else tl = mid + 1;	
    }
    printf("%d\n", tl);
    return 0;
}
