#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5+5;
int a[mx],t,n;
int dp[mx] = {0};
bool mark[mx] = {0};
int get(int id,int prev)
{
	if(id>=n) return 0;
	if(dp[id]!=-1) return dp[id];
	//cout<<a[id]<<" "<<prev<<"\n";
	int v1 = get(id+1,a[id])+1;
	int v2 = get(id+1,prev)+1;
	if(__gcd(a[id],prev)>1) return 1;
	if(v1==v2) return 0;
	if(v1>v2) mark[id]=true;
	else 
	{
		int x = id;
		while(x>=0)
		{
			if(a[x]==prev) break; 
		}
		mark[x]=true;
	}
	return dp[id]=max(v1,v2);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	#endif
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		memset(dp,-1,sizeof dp);
		memset(mark,false,sizeof mark);
		cout<<max(get(1,a[0]),get(2,a[1]))<<"\n";
		int cnt = 0;
		for(int i=0;i<n;i++) if(mark[i]) cnt++;
		cout<<"   "<<cnt<<"\n";
	}
} 