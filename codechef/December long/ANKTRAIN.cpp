#include<bits/stdc++.h>
using namespace std;
main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
//subtask 1
/*int p1 = n%8;
if(p1==3) cout<<"6UB\n";
else if(p1==6) cout<<"3UB\n";
else if(p1==2) cout<<"5MB\n";
else if(p1==5) cout<<"2MB\n";
else if(p1==1) cout<<"4LB\n";
else if(p1==4) cout<<"1LB\n";
else if(p1==7) cout<<"8SU\n";
else if(p1==0) cout<<"7SL\n";*/
//subtask 2
int quo = int(n/8);
int rem = int(n%8);     
int a[9],temp=(8*(quo)+1);
if(rem==0) temp=n-7;
for(int i=1;i<=8;i++,temp++) a[i]=temp;
if(rem==3) cout<<a[6]<<"UB\n";
else if(rem==6) cout<<a[3]<<"UB\n";
else if(rem==2) cout<<a[5]<<"MB\n";
else if(rem==5) cout<<a[2]<<"MB\n";
else if(rem==1) cout<<a[4]<<"LB\n";
else if(rem==4) cout<<a[1]<<"LB\n";
else if(rem==7) cout<<a[8]<<"SU\n";
else if(rem==0) cout<<a[7]<<"SL\n";
}
}