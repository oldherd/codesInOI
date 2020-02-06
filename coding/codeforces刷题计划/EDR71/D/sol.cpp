#include <cstdio>

using namespace std;

char buf[2000000], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,2000000,stdin), p1==p2)?EOF:*p1++; }
#define gc() getchar()
inline void read(int &x) {
    x = 0;
    int f = 1;
    char ch = gc();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = gc(); }
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
    x *= f;
}

int main() {

	return 0;
}


