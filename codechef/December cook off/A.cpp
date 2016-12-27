#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("in","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int a[4],ans=0;
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		int x=pow(2,4)-1;
		for(int i=0;i<=x;i++)
		{
			bool state=false;
			int sum=0;
			for(int j=0;j<4;j++)
			{
				int z=1<<j;
				if(z&i)
				{
					sum+=a[j];
					state=true;
				}
			}
			if(sum==0&&state) ans++;
		}
		//cout<<ans<<"\n";
		if(ans>0) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}