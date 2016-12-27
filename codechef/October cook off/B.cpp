#include<bits/stdc++.h>
using namespace std;
typedef struct my
{
int id;
int pop;
string s;
}my;
bool cmp(const my &a,const my &b)
{
return a.pop>b.pop;
}
main()
{
ios_base::sync_with_stdio(0);
int n,m;
cin>>n>>m;
int a[n+1];
for(int i=0;i<n;i++) cin>>a[i];
sort(a,a+n);
my temp[m];
for(int i=0;i<m;i++)
{
cin>>temp[i].id>>temp[i].pop>>temp[i].s;
}
sort(temp,temp+m,cmp);
for(int i=0;i<m;i++)
{
if(binary_search(a,a+n,temp[i].id))
{
cout<<temp[i].s<<"\n";
temp[i].id = -1;
temp[i].pop = -1;
}
}
for(int i=0;i<m;i++)
{
if(temp[i].id != -1)
{
cout<<temp[i].s<<"\n";
}
}
}