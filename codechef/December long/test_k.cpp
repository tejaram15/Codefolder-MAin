#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5+5;
int a[mx],t,n;
int dp[mx] = {0};
map<int,bool> mark;
int get(int id,int prev)
{
	if(id>=n) return 0;
	if(dp[id]!=-1) return dp[id];
	int v1 = get(id+1,a[id])+1;
	int v2 = get(id+1,prev)+1;
	if(__gcd(a[id],prev)>1) return 1;
	if(v1==v2) return 0;
	cout<<a[id]<<" "<<prev<<"\n";
	if(v1>v2) mark[a[id]] = true;
	else mark[prev] = true;
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
		//memset(mark,false,sizeof mark);
		cout<<get(1,a[2])<<"  ";
		int cnt = 0;
		for(int i=0;i<n;i++) if(mark[a[i]]) cnt++;
		cout<<cnt<<"\n";
	}
} 