#include<bits/stdc++.h>
using namespace std;
main()
{
//freopen("in","r",stdin);
ios_base::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
string a,b;
cin>>a>>b;
int i,d,w;
cin>>i>>d>>w;
int r[26][26];
for(int i=0;i<26;i++)
{
for(int j=0;j<26;j++)
{
cin>>r[i][j];
}
}
int n,m;
n = a.length();
m = b.length();
int dp[n+2][m+2];
memset(dp,0,sizeof dp);
for(int i=0;i<=n;i++) dp[i][0]=i;
for(int j=0;j<=m;j++) dp[0][j]=j;

for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
if(a[i-1]==b[j-1])
{
dp[i][j]=dp[i-1][j-1];
}
else dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
}
}
/*for(int i=0;i<=n;i++)
{
for(int j=0;j<=m;j++)
{
cout<<dp[i][j]<<" ";
}
cout<<"\n";
}*/
cout<<dp[n][m]<<"\n";
}
}