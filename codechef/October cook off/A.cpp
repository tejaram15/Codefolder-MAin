#include<bits/stdc++.h>
using namespace std;
main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int a[n+1];
bool state = true;
for(int i=0;i<n;i++) cin>>a[i];
sort(a,a+n);
for(int i=1;i<n;i++) if(abs(a[i]-a[i-1])>1) state = false;
if(state) cout<<"YES\n";
else cout<<"NO\n";
}
}