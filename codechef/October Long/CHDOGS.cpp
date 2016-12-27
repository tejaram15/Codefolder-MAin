//ACCEPTED

#include<bits/stdc++.h>
using namespace std;
const double result = (double) 2 / 3;
const float giv = 1e-7;
#define EPS 1e6
int main()
{
int t;
cin>>t;
while(t--)
{
int s,v;
cin>>s>>v;
double ans=(double)s*result;
ans=(double)ans/v;
if(ans<giv) ans=giv;
printf("%.7f\n",ans);
}
return 0;
}