#include <cstdio>

using namespace std;

char buf[1<<20], *p1, *p2;
inline char gc() {
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++;
}

inline void read(int &x) {
	char ch = gc();
	while(ch != '0' && ch != '1') ch = gc();
	x = ch-48;
}

int main() {
	freopen("inputB.in", "r", stdin);
	int n, pre, tmp, cnt = 1;
	scanf("%d", &n);
	read(pre);
	if(pre) ++cnt;
	for(int i = 2; i <= n; ++i) {
		read(tmp);
		(tmp^pre) && (++cnt);
		pre = tmp;
	}
	printf("%d\n", cnt);
	return 0;
}
