#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
if(b==0) return a;
return gcd(b,a%b);
}

int main()
{                       
freopen("in","r",stdin);
freopen("out1","w",stdout);
int t,n;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
int a[n+1];
for(int i=0;i<n;i++) scanf("%d",&a[i]);

int dp[2][n+1];
dp[0][0]=a[0];
dp[1][0]=0;

//solution
for(int i=1;i<n;i++)
{

}

cout<<"\n";
for(int i=0;i<n;i++) cout<<dp[0][i]<<"  ";
cout<<"\n";
for(int i=0;i<n;i++) cout<<dp[1][i]<<"  ";
cout<<"\n\n";


cout<<dp[1][n-1]<<"\n";
}
return 0;
}