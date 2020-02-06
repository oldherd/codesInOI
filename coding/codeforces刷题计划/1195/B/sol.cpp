/*
 设放入的蛋糕操作数目为t，显然放入t*(t+1)/2个蛋糕。吃掉的蛋糕数目为n-t，两者相减等于k。
 化简方程得t^2 + 3*t - 2*(n + k) = 0,显然我们要求的n-t的t来源于该方程的正数解。结合二次函数知识可得它在[0,+∞] 单调递增且有零点(唯一)，所以可以二分答案求解。 
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
