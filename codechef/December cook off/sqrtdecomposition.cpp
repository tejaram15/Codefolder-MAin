//Using Square root decomposition
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
const int N = 1111111;
const int mx = 300005;
const int sz = 300005;
int a[sz],cnt[N],block,answer=0,ans[mx+5];
vector<pair<pair<int,int> ,int> > p;
bool cmp(const pair<pair<int,int> ,int> &a,const pair<pair<int,int> ,int> &b)
{
	if(a.f.f/block!=b.f.f/block)
		return a.f.f/block < b.f.f/block;
	return a.f.s < b.f.s;
}
void add(int i)
{
	cnt[a[i]]++;
	if(cnt[a[i]]==1)
	{
		answer++;
	}
}
void remove(int i)
{
	cnt[a[i]]--;
	if(cnt[a[i]]==0)
	{
		answer--;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p.pb(mp(mp(x-1,y-1),i));
	}
	block = sqrt(n);
	sort(p.begin(),p.end(),cmp);
	int prev_l = 0;
	int prev_r = 0;
	for(int i=0;i<q;i++)
	{
		int l = p[i].f.f;
		int r = p[i].f.s;
		while(prev_l<l)
		{
			remove(prev_l);
			prev_l++;
		}
		while(prev_l>l)
		{
			add(prev_l-1);
			prev_l--;
		}
		while(prev_r<=r)
		{
			add(prev_r);
			prev_r++;
		}
		while(prev_r>r+1)
		{
			remove(prev_r-1);
			prev_r--;
		}
		ans[p[i].s] = answer;
	}
	for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
	return 0;
} 