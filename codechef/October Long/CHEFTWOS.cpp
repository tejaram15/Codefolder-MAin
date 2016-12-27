#include<bits/stdc++.h>
using namespace std;

bool is_good(string s)
{
int len = s.length(),i=0,j=0;
bool arr[len],ans = true;
memset(arr,false,sizeof arr);
for(i=0;i<len;)
{
if(s[i]=='1')
{
if(i+1<len-1 && arr[i+1]==false) arr[i+1]=true,i+=1;
else if(i-1>=0 && arr[i-1]==false) arr[i-1]=true,i-=1;
}
else if(s[i]=='2')
{
if(i+2<len-1 && arr[i+2]==false) arr[i+2]=true,i+=2;
else if(i-2>=0 && arr[i-2]==false) arr[i-2]=true,i-=2;
}
}
j=i;
for(i=0;i<len;i++) ans &= arr[i];
if(!(ans&&j==len-1))  return false;
return ans;
}

main()
{
ios_base::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
string a,b;
cin>>a>>b;
cout<<is_good(a)<<"  "<<is_good(b)<<"\n";
}
}