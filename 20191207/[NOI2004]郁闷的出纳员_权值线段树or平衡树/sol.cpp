#include <cstdio>
#include <cstring>

using namespace std;

const int SUM = 123456, SU = 110000;

int dat[SUM<<3], tag[SUM << 3];
inline void update(int p) {
	dat[p] = dat[p<<1] + dat[p<<1|1];
}
inline void spread(int p) {
	dat[p<<1] = dat[p<<1|1] = tag[p<<1] = tag[p<<1|1] = 0;
	tag[p] = -1;
}
void insert(int p, int lp, int rp, int x) {
	if(lp == rp) {
		++dat[p];
		return ;
	}
	int mid = (lp + rp) >> 1;
	if(~tag[p]) spread(p);
	if(x <= mid) insert(p<<1, lp, mid, x);
	else insert(p<<1|1, mid + 1, rp, x);
	update(p);
}
void modify(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) {
		tag[p] = 0; dat[p] = 0;
		return ;
	}
	if(~tag[p]) spread(p);
	int mid = (lp + rp) >> 1;
	if(l <= mid) modify(p<<1, lp, mid, l, r);
	if(r > mid) modify(p<<1|1, mid + 1, rp, l, r);
	update(p); 
}
int qry(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return dat[p];
	int mid=  (lp + rp) >> 1, ans = 0;
	if(~tag[p]) spread(p);
	if(l <= mid) ans = qry(p<<1, lp, mid, l, r);
	if(r > mid) ans += qry(p<<1|1, mid + 1, rp, l, r);
	return ans;
}
int findkth(int p, int lp, int rp, int k) {
	if(lp == rp) return lp;
	int mid = (lp + rp) >> 1;
	if(~tag[p]) spread(p);
	if(dat[p<<1] >= k) return findkth(p<<1, lp, mid, k);
	return findkth(p<<1|1, mid + 1, rp, k - dat[p<<1]);
}

int main() {
//	freopen("unhappy.in", "r", stdin);
//	freopen("unhappy.out", "w", stdout);
	memset(tag, -1, sizeof(tag));
	const int n = (SU<<1) + 10;
	int q, mini, tmp, dlt = 0, cnt = 0;
	scanf("%d %d", &q, &mini);
	char ch[2];
	dlt -= SU; mini += SU;
	while(q--) {
		scanf("%s %d", ch, &tmp);
		if(ch[0] == 'I') {
			tmp -= dlt;
			if(tmp >= mini) insert(1, 1, n, tmp);
		} else if(ch[0] == 'F') {
			if(tmp > dat[1]) printf("-1\n");
			else printf("%d\n", findkth(1, 1, n, dat[1] - tmp + 1) + dlt);
		} else if(ch[0] == 'S') {
			dlt -= tmp; mini += tmp;
				cnt += qry(1, 1, n, 1, mini - 1);
				modify(1, 1, n, 1, mini - 1);
		} else if(ch[0] == 'A') {
			dlt += tmp; mini -= tmp;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
