#include<bits/stdc++.h>
using namespace std;
main()
{
freopen("in","w",stdout);
int t = 10;
cout<<t<<"\n";
while(t--)
{
int n = rand()%10 + 1;
cout<<n<<"\n";
for(int i=0;i<n;i++)
{
int x = rand()%10 +1 ;
cout<<x<<" ";
}
cout<<"\n";
}
}
