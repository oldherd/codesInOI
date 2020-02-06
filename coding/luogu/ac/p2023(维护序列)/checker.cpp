#include <bits/stdc++.h>

using namespace std;

int main() {
	for(int t = 1; t <= 10000; t++) {
		system("gendata.exe > data.in");
		system("sol.exe < data.in > data.out");
		system("std.exe < data.in > data.ans");	
		if(system("fc data.ans data.out")) {
			printf("WA on #%d!\n", t);
			return 0;
		} else {
			printf("AC on #%d\n", t);
		}
	}
	return 0;	
}
