#include <cstdio>

using namespace std;

const int N = 16;

int main() {
	for(int x = 1; x <= N; ++x)
		for(int y = 1; y <= N; ++y)
			for(int z = 1; z <= N; ++z)
			 	if((x ^ y ^ z) == 9) {
					printf("%d %d %d\n", x, y, z);
				}
	return 0;	
}
