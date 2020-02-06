/*
 �����ĵ��������ĿΪt����Ȼ����t*(t+1)/2�����⡣�Ե��ĵ�����ĿΪn-t�������������k��
 ���򷽳̵�t^2 + 3*t - 2*(n + k) = 0,��Ȼ����Ҫ���n-t��t��Դ�ڸ÷��̵������⡣��϶��κ���֪ʶ�ɵ�����[0,+��] ���������������(Ψһ)�����Կ��Զ��ִ���⡣ 
*/
#include <cstdio> 

using namespace std;

int main() {
	int n, k, l = 0, r = 100000;
	scanf("%d %d", &n, &k);
	long long p = - 2 * ((long long)n + k);
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		long long ans = (long long)mid * (mid + 3) + p;
		if(ans <= 0) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", n - l);
	return 0;	
}
