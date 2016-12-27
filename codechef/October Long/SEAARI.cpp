#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int mx = 1e9;
const int a = 0;
const int r = 1;
main()
{
ios_base::sync_with_stdio(0);
int n,k,d,tk,td;
cin>>n>>k>>d;
tk=k;
td=d;
int arr[n+1];
map<int,int> mp;
for(int i=0;i<n;i++) 
{
cin>>arr[i];
mp[arr[i]] = i+1;
}
map<int,int>::iterator beg = mp.begin();
map<int,int>::iterator ed = mp.end();
//always do beg++ , ed-- for swap operation   and only beg-- for delete 
//operation
//bring swap end and begin with the purpose of minimizing the mutual 
//attraction and delete the smaller elements
cout<<"0 1\n";
int cnt=0;
while(1)
{
if(k==0&&d==0) break;
if(cnt==tk+td) break;
if(k>0)
{
cout<<"1 "<<beg->se<<ed->se<<"\n";
beg++;
ed--;
k--;
cnt++;
}
if(d>0)
{
cout<<"2 "<<beg->se<<"\n";
beg++;
d--;
cnt++;
}
}
cout<<"-1";
}