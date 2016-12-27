//trie and bit manipulation
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int nm=100010;
int n,a[nm],k,b[nm];
struct node
{
	node *a[2];
	int cntall;
	node()
	{
		a[0]=a[1]=0;
		cntall=0;
	}
};
node *root;

void add(int n)
{
	node *p=root;
	p->cntall++;
	for(int i=32;i>=0;--i)
	{
		int x=(n>>i)&1;
		if(!p->a[x])
			p->a[x]=new node();
		p=p->a[x];
		p->cntall++;
	}
}
int get(int n)
{
	node *p=root;
	int res=0;
	for(int i=32;i>=0;--i)
	{
		int x=((n>>i)&1)|((k>>i)&1);
		if((k>>i)&1)
		{
			if(p->a[x|1])
				res+=p->a[x|1]->cntall;
		}
		if(!p->a[x])
			return res;
		p=p->a[x];
	}
	return res;
}
void solve() {
	scanf("%d%d", &n, &k);
	root = new node();
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = b[i - 1] | a[i];
	}
	add(b[0]);
	for (int i = 1; i <= n; ++i) {
		res += (ll) get(b[i]);
		add(b[i]);
	}
	printf("%lld\n", res);
}
int main()
{
	freopen("in","r",stdin);
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}