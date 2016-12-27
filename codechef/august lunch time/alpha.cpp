#include<bits/stdc++.h>
using namespace std;
main()
{
string s;
int n;
cin>>s>>n;   
int a[26];
memset(a,0,sizeof(a));
int ln=s.length();
for(int i=0;i<ln;i++) a[s[i]-97]++;
while(n--)
{
string tmp;
cin>>tmp;
int lln=tmp.length();
bool st=true;
for(int i=0;i<lln;i++) st &= (a[tmp[i]-97]>0);                     
if(st) cout<<"Yes\n";
else cout<<"No\n";
}
}