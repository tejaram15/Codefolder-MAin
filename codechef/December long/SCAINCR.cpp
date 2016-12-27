#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define pb push_back
#define mp make_pair
#define f first
#define s second
int a[MAX_N];
int L[MAX_N], L_id[MAX_N], P[MAX_N];
int ans[MAX_N];
int block;

vector<pair<pair<int,int> ,int> > v;

bool cmp(const pair<pair<int,int> ,int> &a,const pair<pair<int,int> ,int> &b)
{
	if(a.f.f/block!=b.f.f/block)
		return a.f.f<b.f.f;
	return a.f.s<b.f.s;
}

int lis_ans(int l,int r)
{
	int lis = 0, lis_end = 0;
	for (int i = l; i <=r; ++i) {
		int pos = lower_bound(L, L + lis, a[i]) - L;
		L[pos] = a[i];
		L_id[pos] = i;
		P[i] = pos ? L_id[pos - 1] : -1;
		if (pos + 1 > lis) {
			lis = pos + 1;
			lis_end = i;
		}
	}
	return lis;
}

int main()
{
	ios_base::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=0;i<m;i++)
		{
			int l,r;
			cin>>l>>r;
			v.pb(mp(mp(l,r),i));
		}
		block = sqrt(n);
		sort(v.begin(),v.end(),cmp);
		int currL = 0, currR = 0;
    	int currSum = 0;
		for(int i=0;i<m;i++)
		{
			int L = v[i].f.f;
			int R = v[i].f.s;
			int idx = v[i].s;
			while (currL < L)
	        {
	            currSum -= a[currL];
	            currL++;
	        }
	        while (currL > L)
	        {
	            currSum += a[currL-1];
	            currL--;
	        }
	        while (currR <= R)
	        {
	            currSum += a[currR];
	            currR++;
	        }
	        while (currR > R+1)
	        {
	            currSum -= a[currR-1];
	            currR--;
	        }
	        ans[idx] = currSum;
		}
		for(int i=0;i<m;i++)
		{
			cout<<ans[i]<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}