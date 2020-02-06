/*
莫队算法的模板题。 
莫队算法适用于能够O(1)维护删除一个点和增加一个点的题目内，复杂度为O(n√n + m√n)。  
初始化将l = 1, r = 0.这样在它们移动到排序后的询问序列过程中的中间段分别被添加和删除各一次，正好抵消。  
每块的大小最好为 n / (√m * 2/3).  
*/
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 50010, maxm = 50010;
int a[maxn], pos[maxn], c[maxn], ans;
struct query{
	int l, r, id, ans;
	bool operator < (const query &o) const { return pos[l] == pos[o.l] ? r < o.r : pos[l] < pos[o.l]; }
}q[maxm];

inline void add(int p) {
	ans -= c[a[p]] * c[a[p]]; c[a[p]]++; ans += c[a[p]] * c[a[p]];
}

inline void del(int p) {
	ans -= c[a[p]] * c[a[p]]; c[a[p]]--; ans += c[a[p]] * c[a[p]];
}

inline bool cmp1(query x, query y) {
	return x.id < y.id;	
}

int main() {
	int n, m, k;
	ans = 0;
	scanf("%d %d %d", &n, &m, &k);
	int block = (int)( n / (sqrt((double)m * 2 / 3)));
	for(int i = 1; i <= n; i++) scanf("%d", a+i);
	for(int i = 1; i <= n; i++) pos[i] = i / block;
	for(int i = 1; i <= m; i++) scanf("%d %d", &q[i].l, &q[i].r), q[i].id = i;
	sort(q+1, q+m+1);
	int l = 1, r = 0;
	for(int i = 1; i <= m; i++) {
		while(l < q[i].l) del(l++);
		while(l > q[i].l) add(--l);
		while(r < q[i].r) add(++r);
		while(r > q[i].r) del(r--);
		q[i].ans = ans;
	}
	sort(q+1, q+m+1, cmp1);
	for(int i = 1; i <= m; i++) printf("%d\n", q[i].ans);
	return 0;	
}
