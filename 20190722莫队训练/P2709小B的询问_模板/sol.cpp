/*
Ī���㷨��ģ���⡣ 
Ī���㷨�������ܹ�O(1)ά��ɾ��һ���������һ�������Ŀ�ڣ����Ӷ�ΪO(n��n + m��n)��  
��ʼ����l = 1, r = 0.�����������ƶ���������ѯ�����й����е��м�ηֱ���Ӻ�ɾ����һ�Σ����õ�����  
ÿ��Ĵ�С���Ϊ n / (��m * 2/3).  
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
