#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 1e6;
const ll MAX = 1e12+7;

int fact[N] = {0};

int main()
{
	freopen("in","r",stdin);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		if(n==1) 
		{
			cout<<"INFINITY\n";
			continue;
		}
		int ans=ceil(int(n/2));
		if(n%2!=0) ans = ans+1;
		long long int i=2,mx = 0;

		if(n<=1000) mx = 50;
		else if(n<=1000000) mx = 2000;
		else mx = mx=ceil(int(n/2));
		if(mx>ceil(int(n/2))) mx=ceil(int(n/2));
		
		if(n<N)
		{
			for(;i<=mx;i++)
			{
				long long int num = n;
				long x = 0;  
				while(num>0)
				{
					x = num%i;
					num/=i;
				}
				if(x==1) ans++;
			}
			cout<<ans<<"\n";
		}
	}
}