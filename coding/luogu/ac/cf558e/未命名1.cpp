#include <cstdio>
#include <set>
#define itra set<app>::iterator

using namespace std;

struct app{
	int l, r;
	bool operator < (const app& o) const { return r < o.r; }
	app(int L, int R) : l(L), r(R) {}
};

set<app> s;

int main() {
	int m, t, g, sum;
	char op[2];
	scanf("%d", &m);
	while(m--) {
		scanf("%s", op);
		if(op[0] == 'A') {
			scanf("%d %d", &t, &g);
			int cnt = 0;
			if(s.empty()) {
				printf("0\n");	
			} else {
			itra it = s.lower_bound(app(0, t));
				while(it != s.end()) {
					if(it->l > g) break;
					itra itt = it;
					it++;
					s.erase(itt); cnt++;
				}
				printf("%d\n", cnt);
			}
			s.insert(app(t, g));
			sum += 1 - cnt;
		} else {
			printf("%d\n", sum);
		}
	}
	return 0;	
}
