//ACCEPTED

#include<bits/stdc++.h>
using namespace std;
main()
{
ios_base::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
int n,m,c;
cin>>n>>m>>c;
int cnt=0;
for(int a=1;a<=c;a++)
{
if(c%a!=0) continue;
int b=c/a;
if(a>n||b>m) continue;
//cout<<a<<" - "<<b<<"\n";
cnt++;
}
cout<<cnt<<"\n";
}
}