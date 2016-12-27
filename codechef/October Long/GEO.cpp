#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define x first
#define y second
#define ll long long int 
main()
{
int n;
cin>>n;
set<pi> st;
long long int res=0;
for(int i=0;i<n;i++)
{
pi p;
cin>>p.x>>p.y;
if(i==0) {cout<<"0\n";st.insert(p);}
else 
{
st.insert(p);
long long int dis=0;
for(auto it:st) 
{
int bx,by,sx,sy;
bx=max(it.x,p.x);
by=max(it.y,p.y);
sx=min(it.x,p.x);
sy=min(it.y,p.y);
dis = 1LL*(bx-sx)*(bx-sx)+1LL*(by-sy)*(by-sy);
if(dis>res) res=dis;
}
cout<<res<<"\n";
}
}
}