#include <cstdio>
#include <bitset>

using namespace std;

const int M = 30010, SGM = 3010;
char buf[1<<20], *p1, *p2;
inline char gc() {
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++;
}

inline void read(int &x) {
	char ch = gc(); x = 0;
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') x=(x<<3)+(x<<1)+(ch&15), ch = gc();
}

bitset<M> t[SGM][3];
int mp[SGM], mx;

int main() {
//	freopen("inputC.in", "r", stdin);
	int n, m, op, num, cnt, flg;
	read(n); read(m);
	for(int i = 1; i <= m; ++i) {
		read(num);
		t[num][0].set(i);
	}
	for(int i = m + 1; i <= n; ++i) read(num);
	for(register int i = 1; i <= m; ++i) {
		read(op); read(num);
		mx = max(mx, num);
		if(op)
		for(register int j = 1; j <= mx; ++j) {
			if(mp[i])
				t[j][1] <<= 1,
				t[j][2] <<= 1;
		}
		op && (t[num][1].set(1), t[num][2].set(1), 1) || (t[num][1].set(i), t[num][2].set(i), 1);
		mp[num] = 1; cnt = 0;
		for(int l = 1; l <= i; ++l) {
			flg = 1;
			for(int j = 1; j <= mx && flg; ++j) 
				if(mp[j]) {
					(t[j][0] & t[j][1]).any() && (flg = 0);
					t[j][1] >>= 1;
				}
			flg && ++cnt;
		}
		printf("%d\n", cnt);
		for(int j = 1; j <= mx; ++j) if(mp[j]) t[j][1] = t[j][2];
	}
	return 0;
}
