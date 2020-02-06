#include <cstdio>

using namespace std;

const int maxn = 1000010;
int a[maxn], au = 0;

const int sz = 2000000;
char buf[2000000], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin), p1==p2)?EOF:*p1++; }
inline void read(int &x) {
    x = 0; char ch = gc();
    while(ch < '0' || ch > '9') ch = gc();
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
}

int main() {
	
	int n, t;
	bool flag;
	read(n);
	for(int i = 1; i <= n; i++) {
		flag = false;
		read(t);
		for(int j = 0; j < au; j++)
			if((a[j]^t) <= (a[j]+t)) {
				flag = true;
				a[j] ^= t;
				break;
			}
		if(!flag) {
			a[au++] = t;	
		}
	}
	t = 0;
	for(int i = 0; i < au; i++) t += a[i];
	printf("%d\n", t);
	return 0;	
}
