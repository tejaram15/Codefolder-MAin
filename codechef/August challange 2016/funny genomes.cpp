/********************
   Coded by -Ram
*********************/

#include<bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0);
int mat[501][501],n,m,k,x;
//set<int> st;
using namespace std;
main()
{
  fast_io;
  cin>>n;
  vector<int> adjlst[n+1];
  for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++){
    cin>>mat[i][j];
    if(mat[i][j]==1) adjlst[i].push_back(j);
   }
  }
  cin>>m;
  vector<int> child;
  while(m--)
  {
    cin>>k>>x;
    child.clear();
    st.clear();
    if(!adjlst[x].empty())
      copy(adjlst[x].begin(),adjlst[x].end(),child.begin());
    for(int i=0;i<adjlst[x].size();i++)
      if(st.find(adjlst[x][i])!=st.end())
         st.insert(adjlst[x][i]);
  }
}
