#include <bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
const int mx=2e5;
int block,ans[mx],answer=0,n,q,a[mx];
unordered_map<int,int> mp;
struct sq
{
	int l,r,k,idx;
};
bool cmp(const sq &a,const sq &b)
{
	if(a.l/block!=b.l/block)
		return a.l/block < b.l/block;
	return a.r < b.r;
}
inline void read(int &x)
{
	register int c = gc();
	x = 0;
	bool neg = false;
	for(;(c<48)||(c>57);c=gc())
	{
		if(c=='-') neg = true;
	}
	for(;(c>47)&&(c<58);c=gc())
		x = (x<<1) + (x<<3) + (c-48);	
	if(neg) x = -x;
}
inline void write(long long int n)
{
	bool neg = (n<0);
	if(n == 0)
	{
		pc('0');
		pc('\n');
	}
	else if(n == -1)
	{
		pc('-');
		pc('1');
		pc('\n');
	}
	else
	{
		if(neg) n=-n,pc('-');
		char buf[20];
		buf[19] = '\n';
		int i = 18;
		while(n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while(buf[i] != '\n')
			pc(buf[++i]);
	}
}
void add(int i,int k)
{
	mp[a[i]]++;
}
void remove(int i,int k)
{
	mp[a[i]]--;
}
int main()
{
	freopen("in","r",stdin);
	int t;
	read(t);
	while(t--)
	{
		mp.clear();
		read(n);
		read(q);
		for(int i=0;i<n;i++) read(a[i]);
		sq node[q];
		for(int i=0;i<q;i++)
		{
			node[i].idx=i;
			read(node[i].l);
			read(node[i].r);
			read(node[i].k);
			node[i].l--;
			node[i].r--;
		}
		block=sqrt(n);
		sort(node,node+q,cmp);
		int prev_l = 0;
		int prev_r = 0;
		for(int i=0;i<q;i++)
		{
			int l = node[i].l;
			int r = node[i].r;
			int k = node[i].k;
			while(prev_l>l)
			{
				add(prev_l-1,k);
				prev_l--;
			}
			while(prev_r<=r)
			{
				add(prev_r,k);
				prev_r++;
			}
			while(prev_l<l)
			{
				remove(prev_l,k);
				prev_l++;
			}
			while(prev_r>r+1)
			{
				remove(prev_r-1,k);
				prev_r--;
			}
			answer=0;
			for(auto it:mp)
			{
				if(it.first==0) continue;
				if(it.second<=k&&it.second>0) answer++;
			}
			ans[node[i].idx] = answer;
		}
		for(int i=0;i<q;i++) write(ans[i]);
		pc('\n');		
	}
	return 0;
}