#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N];
int a[N];
int t,n;

inline int gcd(int a,int b)
{
if(b==0) return a;
return gcd(b,a%b);
}


int rec(int i,int prev)
{
if(i>=n) return 0;
if(dp[i]!=-1) return dp[i];
if(gcd(a[i],prev)>1) return 1;
int v1 = rec(i+1,a[i])+1;
int v2 = rec(i+1,prev)+1;
if(v1==v2) return 0;
int ans = max(v1,v2);
//cout<<a[i]<<" "<<prev<<"\n";
return dp[i]=ans;
}

int main()
{                       
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
for(int i=0;i<n;i++) scanf("%d",&a[i]);
memset(dp,-1,sizeof dp);
cout<<rec(1,a[0])<<"\n";
}
return 0;
} 