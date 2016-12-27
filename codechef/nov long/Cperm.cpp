#include<bits/stdc++.h>
using namespace std;
main()
{
ios_base::sync_with_stdio(0);
int t,n;
cin>>t;
while(t--)
{
cin>>n;
int cnt = 0;
int a[n+1];
for(int i=1;i<=n;i++) a[i]=i;
do
{
bool state = true;
for(int i=2;i<=n-1;i++)
{
for(int j=i;j<=n-1;j++)
{
state &=(a[j]>a[j+1]);
}
for(int j=2;j<=i;j++)
{
state &= (a[j]>a[j-1]);
}
if(state) 
{
cnt++;
//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//cout<<"\tcnt = "<<cnt<<"\n";
//cout<<std::flush;
}
}
}while(next_permutation(a+1,a+n+1));
cout<<cnt<<"\n";
cout<<flush;
}
}