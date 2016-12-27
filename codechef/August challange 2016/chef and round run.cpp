//Coded by
	//-Ram
	//Tle Man
#include<iostream>
#include<set>

inline int scan()
{
		int z=0;
		char c;
		do{ c=getchar(); } while(c<'0');
		for(;c>='0';c=getchar()) z = (z<<3) + (z<<1) + (c&15);
		return z;
}

using namespace std;

main()
{
   ios_base::sync_with_stdio(0);
   set<int> st;
   int t,n;t=scan();
   while(t--)
   {
     n=scan();
     int a[n+1],f[n+1],i,j,cnt=0;
     for(i=1;i<=n;i++) f[i]=0;
     for(i=1;i<=n;i++)
     {
       a[i]=scan();
       f[i] = (i+a[i])%n+1;
     }
     for(i=1;i<=n;i++)
     {
       st.clear();
       j=f[i];
       while(1)
       {
         st.insert(j);
         if(a[j]==0) (j++)%n+1;
         else j=(j+a[j])%n+1;
         if(j==i)
         {
           cnt++;break;
         }
         else if(st.find(j)!=st.end()) break;
       }
     }
     cout<<cnt<<"\n";
   }
}
