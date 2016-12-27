#include<bits/stdc++.h>
using namespace std;
int swp(int *a,int *b)
{
(*a) ^= (*b);
(*b) ^= (*a);
(*a) ^= (*b);
return 0;
}
main()
{
ios_base::sync_with_stdio(0);
int t,k;
cin>>t;
while(t--)
{
cin>>k;
if(k==1) cout<<"1\n";
else if(k==3)
{
cout<<"3 2 1\n1 3 2\n2 1 3\n";
}          
else if(k==5)
{
cout<<"3 4 1 5 2\n1 2 4 3 5\n2 3 5 4 1\n5 1 3 2 4\n4 5 2 1 3\n";
}
else 
{
int mat[k+1][k+1];
memset(mat,0,sizeof mat);
for(int i=1;i<=k;i++) mat[i][i] = k;

int fin_i=2,fin_j=0,fin_cnt=1,i=2,j=1,cnt=1;
while(1)
{
if(fin_i>k) break;
i=fin_i;
j=1;
cnt=fin_cnt;
while(1)
{
if(i>k||j>k) break;
mat[i][j] = cnt;
i++;j++;
}
fin_i++;
fin_cnt++;
}

fin_i=1,fin_j=2,fin_cnt=k-1,i=1,j=2,cnt=k-1;
while(1)
{
if(fin_j>k) break;
i=fin_i;
j=fin_j;
cnt=fin_cnt;
while(1)
{
if(i>k||j>k) break;
mat[i][j] = cnt;
i++;j++;
}
fin_j++;
fin_cnt--;
}

for(int j=1;j<=k;j++)
{
swp(&mat[1][j],&mat[((k+1)/2)+1][j]);
}
for(int i=1;i<=k;i++)
{
swp(&mat[i][((k+1)/2)-1],&mat[i][k-1]);
} 

for(int i=1;i<=k;i++)
{
for(int j=1;j<=k;j++)
{
cout<<mat[i][j]<<" ";
cout<<flush;
}
cout<<"\n";
}
}
}
}