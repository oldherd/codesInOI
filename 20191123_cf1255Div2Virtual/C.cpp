#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

const int N = 123456;

struct tre{
	int a, b, c;
	tre() {}
	tre(int A, int B, int C): a(A), b(B), c(C) {}
	bool exi(int t) { return a == t || b == t || c == t; }
	int minu(int x, int y) { return a ^ b ^ c ^ x ^ y; }
};
vector<tre> v[N];
vector<int> ans;
int vis[N];

void make(int pre, int now) {
	ans.pb(now);
	for(int i = 0; i < v[now].size(); ++i)
		if(v[now][i].exi(pre)) {
			int tmp = v[now][i].minu(now, pre);
			if(vis[tmp]) continue;
			vis[tmp] = 1;
			make(now, tmp);
			return;	
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, c, d11 = -1, d12 = -1, d21 = -1, d22 = -1;
	cin >> n;
	for(int i = 1; i < n - 1; ++i) {
		cin >> a >> b >> c;
		tre tmp(a, b, c);
		v[a].pb(tmp);
		v[b].pb(tmp);
		v[c].pb(tmp);
	}
	for(int i = 1; i <= n; ++i) {
		if(v[i].size() == 1) {
			if(~d11) d12 = i;
			else d11 = i;
		} else if(v[i].size() == 2) {
			if(~d21) d22 = i;
			else d21 = i;
		}
	}
	ans.pb(d11);
	if(v[d11][0].exi(d21)) {
		vis[d11] = vis[d21] = 1;
		make(d11, d21);
	} else {
		vis[d11] = vis[d22] = 1;
		make(d11, d22);
	}
	for(int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
