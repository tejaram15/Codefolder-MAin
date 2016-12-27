#include<bits/stdc++.h>
const int N = 1e5;
const int MX = 1e7;
using namespace std;
main()
{
freopen("in","w",stdout);
srand(time(NULL));
int n=4;
cout<<n<<"\n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
int x = rand()%3;
cout<<x<<" ";
}
cout<<"\n";
}
}