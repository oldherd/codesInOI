#include <iostream>
#include <queue>

using namespace std;

string str[110];
int martix[30][30],ind[30],ans[30],ap=0;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	int n,l1,l2,p;
	bool flag=true;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>str[i];
	for(int i=1; i<n&&flag; i++) {
		l1=str[i].length();
		for(int j=i+1; j<=n;j++) {
			p=0; l2=str[j].length();
			while(p<l1&&p<l2&&str[i][p]==str[j][p]) p++;
			if(p==l1) continue;
			if(p==l2) { flag=false; break; }
			if(!martix[str[i][p]-'a'][str[j][p]-'a']) {
				ind[str[j][p]-'a']++;
				martix[str[i][p]-'a'][str[j][p]-'a']=1;
			}
		}
	}
	if(!flag) { cout<<"Impossible"<<endl; return 0;	}
	for(int i=0; i<26; i++) if(!ind[i]) q.push(i),ans[ap++]=i;
	while(!q.empty()) {
		int cur=q.front(); q.pop();
		for(int i=0; i<26; i++)
			if(martix[cur][i]&&!(--ind[i])) {
				q.push(i); ans[ap++]=i;
			}
	}
	if(ap!=26) { cout<<"Impossible"<<endl; return 0; }
	for(int i=0; i<ap; i++) cout<<(char)(ans[i]+'a');
	cout<<endl;
	return 0;
}
