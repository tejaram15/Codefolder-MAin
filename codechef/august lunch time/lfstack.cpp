#include<bits/stdc++.h>
using namespace std;
#define pb push_back
struct vect
{
vector<int> a;
};
int main()
{
ios_base::sync_with_stdio(0);
int t,n;
cin>>t;
while(t--)
{
cin>>n;
int mx=0;
vect vc[n];
for(int i=0;i<n;i++)
{
int tp,tpp;
cin>>tpp;mx+=tpp;
for(int j=0;j<tpp;j++) {cin>>tp; vc[i].a.pb(tp);}
}
int sq;
vector<int> v1;
for(int i=0;i<mx;i++) {cin>>sq;v1.pb(sq);}
stack<int> st;
if(n!=1)
{
for(int i=0;i<n;i++)
{
if(!vc[i].a.empty())
	for(int j=0;j<(int)vc[i].a.size();j++)  st.push(vc[j].a[i]);
}
}
else
{
for(int i=0;i<n;i++)
{
if(!vc[i].a.empty())
	for(int j=0;j<(int)vc[i].a.size();j++)  st.push(vc[i].a[j]);
}
}
vector<int> act;
while(!st.empty())
{
int o=st.top();
st.pop();
act.pb(o);
}
for(int i=0;i<(int)act.size();i++) cout<<act[i]<<" - ";
cout<<"\n";
if(equal(v1.begin(),v1.end(),act.begin())) cout<<"Yes";
else cout<<"No";
cout<<"\n";
}
return 0;
}