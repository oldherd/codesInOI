/*
这题很显然是一个贪心，能够配对的配对，不能的则有一半(上取整)能配对。
考虑k<=1000 ,所以只要开桶来存储即可。
如果增大k并且饮料标号不连续，则可以考察hash，并卡掉离散化。 
我们动态地统计不成对数，每当成对减一，不成对加一，然后用全部数值减去得到成对数。可以用已获来实现，或者直接记录数量来判断奇偶性。  
*/
#include <cstdio>

using namespace std;

const int maxk = 1010;
int a[maxk];

int main() {
	int n, k, lft = 0, t;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &t);
		if(a[t]) lft--;
		else lft++;
		a[t] ^= 1;
	}
	printf("%d\n", n - lft + (lft + 1) / 2);
	return 0;	
}
