//Coded by
	//-Ram
#include<bits/stdc++.h>

using namespace std;

main()
{
   ios_base::sync_with_stdio(0);
   int t,n,m;
   cin>>t;
   while(t--)
   {
     string s;
     cin>>n>>m;
     if(n==1)
     {
       if(m&1) s="No";
       else s="Yes";
     }
     else if(m==1)
     {
       if(n&1) s="No";
       else s="Yes";
     }
     else if((n*m)&1) s="No";
     else s="Yes";
     cout<<s<<"\n";
   }
}
