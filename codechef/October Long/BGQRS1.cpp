#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void Factors(int n,int &two,int &five)
{
while (n%2 == 0)
{
two++;
n = n/2;
}
for (int i = 3; i <= sqrt(n) ; i = i+2)
{
if(i>5) break;
while (n%i == 0)
{
if(i==5) five++; 
n = n/i;
}
}
if (n==5) five++;
}

struct mul
{
int two,five;
mul(){two=0;five=0;}
};

main()
{
ios_base::sync_with_stdio(0);
int t,n,m;
cin>>t;
while(t--)
{
cin>>n>>m;
int a[n+1];
int type,l,r,x;
mul arr[n+1];
memset(&arr,0,sizeof arr);
for(int i=0;i<n;i++) 
{
cin>>a[i];
Factors(a[i],arr[i].two,arr[i].five);
}
int cnt=0;
for(int i=0;i<m;i++)
{
cin>>type;
if(type==1)
{
cin>>l>>r>>x;
l--;
mul x_fac;
x_fac.two = 0;
x_fac.five = 0;
Factors(x,x_fac.two,x_fac.five);
for(int i=l;i<r;i++)
{
a[i]*=x;
arr[i].two += x_fac.two;
arr[i].five += x_fac.five;
}
mul temp;
}
else if(type==2)
{
cin>>l>>r>>x;
l--;
mul x_fac;
x_fac.two = 0;
x_fac.five = 0;
Factors(x,x_fac.two,x_fac.five);
for(int i=l;i<r;i++)
{
a[i]=(i-l+1)*x;
arr[i].two = 0;
arr[i].five = 0;
Factors((i-l+1),arr[i].two,arr[i].five);
arr[i].two += x_fac.two;
arr[i].five += x_fac.five;
}
mul temp;
}
else if(type==3)
{
cin>>l>>r;
l--;
int t=0,f=0;
for(int i=l;i<r;i++)
{
t+=arr[i].two;
f+=arr[i].five;
}
mul temp;
cnt+=min(t,f);
}
}
cout<<cnt<<"\n";
}
}  