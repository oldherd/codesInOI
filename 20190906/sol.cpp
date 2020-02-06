#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 60;
int mp[maxn][maxn], stu[maxn], bc[maxn], mfa[maxn], n;
bool vis[maxn];

bool dfs(int cur) {
	for(int i = 1; i <= n; i++)
		if(mp[cur][i] && !vis[i] && stu[i]) {
			vis[i] = true;
			if(!mfa[i] || dfs(mfa[i])) {
				mfa[i] = cur;
				return true;	
			}
		}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	int t, tmp;
	bool flag;
	cin >> t;
	while(t--) {
		memset(mfa, 0, sizeof(mfa)); flag = true;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> tmp; stu[i] = tmp;
		}
		for(int i = 1; i <= n; i++) {
			cin >> tmp; bc[i] = tmp;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				cin >> mp[i][j];
			mp[i][i] = stu[i];
		}
		for(int i = 1; i <= n; i++) {
			if(!stu[i] || !bc[i]) {
				memset(vis, 0, sizeof(vis));
				if(!dfs(i)) {
					flag = false; break;
				}
			}
		}
		if(flag) cout << "^_^" << endl;
		else cout << "T_T" << endl;	
	}
	return 0;	
}
