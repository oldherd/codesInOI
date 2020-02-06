#include <cstdio>
#include <algorithm>

using namespace std;

const int maxs=(1<<10)+10,maxm=15,maxn=110;
int f[maxs][maxs][maxn],Map[maxn],stt[maxs];

inline int geth() {
	char ch=getchar();	
	while(ch!='H'&&ch!='P') ch=getchar();
	return ch=='H'?1:0;
}

inline bool isState(int i) {
	return !(i&(i<<1)) && !(i&(i<<2));
}

int main() {
	int n,m,ans=0;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			Map[i]=(Map[i]<<1)|geth();
	for(int j=0, Size=1<<m; j<Size; ++j) {
		for(int t=j; t; t>>=1) (t&1)&&(++stt[j]);
		isState(j)&&!(Map[1]&j)&&(f[j][0][1]=stt[j]);
	}
	for(int i=2; i<=n; ++i) {
		for(int j=0, Size=1<<m; j<Size; j++)
			if(isState(j)&&!(Map[i]&j))
				for(int k=0; k<Size; k++) {
					if(isState(k)&&!(k&j)&&!(Map[i-1]&k))
						for(int s=0; s<Size; s++)
							isState(s)&&!(s&j)&&!(s&k)&&(f[j][k][i]=max(f[j][k][i],f[k][s][i-1]));
					f[j][k][i]+=stt[j]; ans=max(ans,f[j][k][i]);
				}
	}
	printf("%d\n", ans);
	return 0;
}
