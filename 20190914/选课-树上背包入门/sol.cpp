#include <iostream>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f, maxn = 310;
int head[maxn], ver[maxn<<1], nex[maxn<<1], w[maxn], f[maxn][maxn], tot, m;
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;	
}

void dfs(int epre, int cur) {
	f[cur][1] = w[cur];
	for(int i = head[cur]; i != -1; i = nex[i])
		if((i^1) != epre) {
			dfs(i, ver[i]);
			for(int j = m+1; j > 0; --j)
				for(int k = 0; k <= j; k++)
					f[cur][j] = max(f[cur][j], f[cur][j-k]+f[ver[i]][k]);
		}
	f[cur][0] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	memset(head, -1, sizeof(head));
	memset(f, -inf, sizeof(f));
	int n, v;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> v >> w[i];
		addedge(i, v); addedge(v, i);
	}
	dfs(-1, 0);
	cout << f[0][m+1] << endl;
	return 0;
}

//���ϱ���,�ֳ�������������,��ÿһ���ڵ㿪һ������,dfsʱ����ɨһ�������Ʒ����.
//ϸ�ڵĴ������:�ҵĽⷨ�ǽ���ʼֵ��Ϊ-inf,���õ��Ȩ�طŵ�ѡ1�ſ���Ϊ��ʼ��,�ڱ���������ʱ��0��ֵΪ0��ʾ��ѡ��������  
//lyd���ϵ��������Ȳ���,f�ĳ�ʼֵ��Ϊ0,Ȼ�������ǿ��ѡ������Ʒ(f[cur][i] = f[cur][i-1] + w[i]).
