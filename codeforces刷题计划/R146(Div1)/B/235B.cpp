#include <cstdio>

using namespace std;

int main() {
	double ans=0,pi=0,len=0,lt=0;
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lf",&pi);
		ans+=((len+1)*(len+1)-len*len)*pi;
		len=(len+1)*pi;
	}
	printf("%.10lf\n", ans);
	return 0; 
}
