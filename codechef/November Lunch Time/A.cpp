//chef and students
#include<bits/stdc++.h>
using namespace std;
main()
{
ios_base::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
string s;
cin>>s;
int n = s.length();
for(int i=0;i<n;i++)
{
if(s[i]=='*') continue;
else if(s[i]=='<') s[i] = '>';
else if(s[i]=='>') s[i] = '<';
}                
//cout<<"\n"<<s<<"\n";
int ans = 0;
for(int i=0;i<n-1;i++)
{
if(s[i]=='*')continue;
else if(s[i]=='>'&&s[i+1]=='<') ans++;
}
cout<<ans<<"\n";
}
}