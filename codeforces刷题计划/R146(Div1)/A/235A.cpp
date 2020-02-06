#include <iostream>
#define ull unsigned long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n==1||n==2) cout<<n<<endl;
	else if(n%2) cout<<(ull)n*(n-1)*(n-2)<<endl;
	else if(n%3) cout<<(ull)n*(n-1)*(n-3)<<endl;
	else cout<<(ull)(n-1)*(n-2)*(n-3)<<endl;
	return 0;
}