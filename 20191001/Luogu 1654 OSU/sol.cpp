#include <cstdio>

using namespace std;

int main() {
	int n;
	double d1=0,d2=0,pi,sco=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%lf", &pi);
		sco=(3*d2+3*d1+1)*pi;
		d2=(d2+d1*2+1)*pi;
		d1=(d1+1)*pi;
	}
	printf("%.1lf\n", sco);
	return 0;	
}
