#include <cstdio>
#include <cstring>

using namespace std;

const int N = 123;
char s1[N], s2[N];


int main() {
	int t, pa, pb, pc, cnt, n;
	scanf("%d", &t);
	while(t--) {
		memset(s2, 0, sizeof(s2));
		cnt = 0;
		scanf("%d %d %d %d %s", &n, &pa, &pb, &pc, s1);
		int len = strlen(s1);
		for(int i = 0; i < len; ++i) {
			if(s1[i] == 'R') {
				if(pb) {
					--pb; s2[i] = 'P'; ++cnt;
				}
			} else if(s1[i] == 'P') {
				if(pc) --pc, s2[i] = 'S', ++cnt;
			}
			else if(s1[i] == 'S') {
				if(pa) --pa, s2[i] = 'R', ++cnt;
			}
		}
		if((n + 1) / 2 <= cnt) {
			printf("YES\n");
			for(int i = 0; i < n; ++i) {
				if(!s2[i]) {
					if(pa) --pa, s2[i] = 'R';
					else if(pb) --pb, s2[i] = 'P';
					else --pc, s2[i] = 'S';
				}
			}
			printf("%s\n", s2);
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
