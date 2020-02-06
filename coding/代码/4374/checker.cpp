#include <bits/stdc++.h>

using namespace std;

inline void build() {
	system("g++ sol.cpp -o sol -O3");
	system("g++ std.cpp -o std -O3");
	system("g++ gendata.cpp -o gendata -O3");
}

int main() {
	build();
	int n, de;
	printf("input the num of cases:");
	scanf("%d", &n);
	de = n / 100;
	for(int t = 1; t <= n; t++) {
		system("./gendata > disr.in");
		system("./sol < disr.in > disr.out");
		system("./std < disr.in > disr.ans");
		if(system("diff disr.out disr.ans")) {
			printf("Wa on #%d\n", t);
			return 0;
		} else if(!(t % de)) {
			printf("%d%% finished\n", t / de);
		}
	}
	printf("totally accepted!\n");
	return 0;
}
