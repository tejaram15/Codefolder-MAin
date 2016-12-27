#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

main()
{
int t,n,m,x,y,z;

vector<vii> AdjList;

cin>>t;

while(t--)
{                       
cin>>n>>m;

AdjList.assign(n, vii()); 

for (int i = 0; i < m; i++) {
cin>>x>>y>>z;
x--;y--;
AdjList[x].pb(mp(y, z));
}

int s,d,edge=0,cnt=0;

cin>>s>>d;

vi dist(n, INF); dist[s] = 0;

for (int i = 0; i < n - 1; i++)  // relax all E edges V-1 times, overall O(VE)
for (int u = 0; u < n; u++)                        // these two loops = O(E)
for (int j = 0; j < (int)AdjList[u].size(); j++) {
ii v = AdjList[u][j];        // we can record SP spanning here if needed
int cp=dist[v.first];
dist[v.first] = min(dist[v.first], dist[u] + v.second);
if(dist[v.first]==cp) edge+=cp;
else cnt+=v.second;   
}
/*
  bool hasNegativeCycle = false;
for (int u = 0; u < n; u++)                          // one more pass to check
for (int j = 0; j < (int)AdjList[u].size(); j++) {
ii v = AdjList[u][j];
if (dist[v.first] > dist[u] + v.second)                 // should be false
hasNegativeCycle = true;     // but if true, then negative cycle exists!
}
if (!hasNegativeCycle)
*/
for (int i = 0; i < n; i++)
printf("SSSP(%d, %d) = %d\n", s, i+1, dist[i]);
cout<<"edge="<<edge<<"\tcnt="<<cnt<<"\n";
}
}