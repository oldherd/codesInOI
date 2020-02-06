#include <cstdio>
#include <set>
#define itra set<node>::iterator

using namespace std;

struct node{
	int s, e;
	bool operator < (const node& o) const { return e == o.e ? s < o.s : e < o.e; }
	node(int S, int E) :  s(S), e(E) {}
};

set<node> s;

int main() {
	char op[2];
	int m, l, r;
	scanf("%d", &m);
	while(m--) {
		scanf("%s %d %d", op, &l, &r);
		if(op[0] == 'A') {
			itra it = s.lower_bound(node(0, l));
			int cnt = 0;
			while(it != s.end()) {
				
			}
		} else {
				
		}
	}
	return 0;	
}
