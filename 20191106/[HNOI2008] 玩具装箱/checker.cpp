#include <bits/stdc++.h>

using namespace std;

int main() {
	for(int i = 1; i <= 10000; ++i) {
		system("gendata.exe > data.in");
		system("bf.exe < data.in > data.ans");
		system("sol.exe < data.in > data.out");
		if(system("fc data.out data.ans")) {
			printf("WA on %d\n", i);
			return 0;
		}
		printf("AC on %d\n", i);
	}
	return 0;	
}
