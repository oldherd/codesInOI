#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define itra vector<int>::iterator

using namespace std;

const int N = 123456, M = 1234567;
int head[N], deg[N], ver[M<<1], vis[M<<1], nex[M<<1], tot;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

vector<int> va[N/10];
vector<int> sta;


int instack[N], vist[N], tt;
void dfs(int cur) {
	vist[cur] = 1;
	for(int i = head[cur]; ~i; i = nex[i])
		if(!vis[i]) {
			vis[i] = vis[i^1] = 1;
			head[cur] = nex[i];
			dfs(ver[i]);
			if(instack[ver[i]]) {
				va[tt].push_back(ver[i]);
				while(sta.back() != ver[i]) {
					va[tt].push_back(sta.back());
					instack[sta.back()] = 0;
					sta.pop_back();
				}
				va[tt].push_back(ver[i]);
				++tt;
			} else {
				sta.push_back(ver[i]);
				instack[ver[i]] = 1;
			}
		}
}

int main() {
	memset(head, -1, sizeof(head));
	int n, m, u, v, f, t, flg = 1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d %d %d", &u, &v, &f, &t);
		if(f^t) {
			addedge(u, v); addedge(v, u);
			++deg[u]; ++deg[v];
		}
	}
 	for(int i = 1; i <= n; ++i) {
 		if(deg[i]%2) {
 			flg = 0;
 			break;
 		}
 	}
 	if(!flg) {
 		printf("NIE\n");
 		return 0;
	 }
	 for(int i = 1; i <= n; ++i) 
	 	if(!vist[i]) {
	 		dfs(i);
	 		if(instack[i]) {
	 			va[tt].push_back(i);
	 			while(!sta.empty()) {
	 				va[tt].push_back(sta.back());
	 				instack[sta.back()] = 0;
	 				sta.pop_back();
	 			}
	 			++tt;
	 		}
	 	}
	 printf("%d\n", tt);
	 for(int i = 0; i < tt; ++i) {
	 	printf("%d ", va[i].size()-1);
	 	for(itra it = va[i].begin(); it != va[i].end(); ++it) {
	 		printf("%d ", (*it));
	 	}
	 	printf("\n");
	 }
	return 0;
}
