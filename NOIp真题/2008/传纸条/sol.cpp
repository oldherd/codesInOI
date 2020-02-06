#include <iostream>

using namespace std;

const int maxn=60;
int f[maxn<<1][maxn][maxn],a[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];
    f[2][1][2]=a[1][2]+a[2][1];
    for(int i=3; i<=n+m-1; i++)
        for(int j=1; j<=n&&j<=i; j++)
            for(int k=j+1; k<=n&&k<=i; k++) {
                f[i][j][k]=max(f[i-1][j][k],f[i][j][k]);
                f[i][j][k]=max(f[i-1][j-1][k],f[i][j][k]);
                j+1!=k && (f[i][j][k]=max(f[i-1][j][k-1],f[i][j][k]));
                f[i][j][k]=max(f[i-1][j-1][k-1],f[i][j][k]);
                f[i][j][k]+=a[j][i-j+1]+a[k][i-k+1];
            }
    cout<<f[n+m-2][n-1][n]<<endl;
    return 0;
}
