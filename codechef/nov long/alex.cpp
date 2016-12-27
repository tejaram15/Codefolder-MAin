#include<bits/stdc++.h>
using namespace std;
#define L_MAX 4999999999999999999;
unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
{
if(a==0) return b;
return gcd(b%a,a);
}
main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
unsigned long long int a[n+1];
for(int i=0;i<n;i++) cin>>a[i];
unsigned long long int lcm = L_MAX;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(i!=j)
{
unsigned long long int temp = (unsigned long long int)((1LL * a[i] * a[j]) / (1LL * gcd(a[i],a[j])));
if(lcm>temp) lcm = temp;
}
}
}
cout<<lcm<<"\n";
}
}