#include <cstdio>

using namespace std;

const int bs = 1<<21, maxn = 100010, maxq = 7000010;

int n, m, q, t, mns = 0;
int buc[maxq+maxn], pb = 0;
double p;

struct que{
    int data[maxq], l, r;
    que(int L = 0, int R = 0) : l(L), r(R) {}
    inline int top() {
	if(l == r) return -1;
	return this->data[l];
    }
    inline int pop() {
	if(l == r) return -1;
	return this->data[l++];
    }
    inline void push(int v) {
	this->data[r++] = v;
    }
    inline void restore() {
	for(int i = l; i != r; i++)
	    buc[pb++] = data[i];
    }
}q[3];
    
inline char gc() {
    static char buf[bs], *p1 = buf, *p2 = buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,bs,stdin),p1==p2)?EOF:*p1++;
}

inline void read(int &x) {
    x = 0; char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x=(x<<3)+(x<<1)+(ch&15), ch = gc();
}

inline bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int u, v, ob;
    read(n); read(m); read(q); read(u); read(v); read(t);
    p = (double)u / v; ob = m / t;
    for(int i = 0; i < n; i++) read(q.data[i]);
    sort(q, q+n, cmp);
    for(int tm = 1; tm <= m; t++) {
	int mn = q[0].top(), idm = 0;
	if(q[1].top() > mn) mn = q1.top(), idm = 1;
	if(q[2].top() > mn) mn = q2.top(), idm = 2;
	q[idm].pop();
	if(tm % ob) printf("%d ", nm + mns);
	q[1].push((int)(p*mn) - q);
	q[2].push(mn - (p*mn) - q);
	mns += q;
    }
    puts("");
    for(int i = 0; i < 3; i++) q[i].restore();
    sort(buc, buc+pb, cmp);
    for(int i = 0; i != pb; i++) printf("%d ");
    puts("");
    return 0;
}
