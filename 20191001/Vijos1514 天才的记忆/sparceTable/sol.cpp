#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const int maxn=200010,maxt=30;
int f[maxn][maxt],a[maxn],n;
inline void prework() {
    int t=log(n)/log(2);
    for(int i=1; i<=n; i++) f[i][0]=a[i];
    for(int l=1; l<=t; l++)
        for(int i=1; i+(1<<l)<=n+1; i++)    
            f[i][l]=max(f[i][l-1],f[i+(1<<(l-1))][l-1]);
}

inline int qry(int l, int r) {
    int le=log(r-l+1)/log(2);
    return max(f[l][le],f[r-(1<<le)+1][le]);
}

int main() {
    int m,l,r;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d",a+i);
	prework();
    scanf("%d",&m);
    while(m--) {
        scanf("%d %d", &l, &r);
		printf("%d\n", qry(l,r));
    }
    return 0;
}
