#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int t,n,las;
string str;
long long a,b,ans;
int main()
{
	cin>>t;
	while(t--)
	{
		ans=las=0;
		cin>>n>>a>>b;
		cin>>str;
		ans=b*(n+1)+a*n;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='1') ans+=2*b;
			if(str[i]=='1'&&!las) las=i;
			else if(str[i]=='1')
				ans+=min(2*a,(i-las-2)*b),las=i;
		}
		printf("%lld\n",ans+(las?2*a:0));
	}
	return 0;
}
