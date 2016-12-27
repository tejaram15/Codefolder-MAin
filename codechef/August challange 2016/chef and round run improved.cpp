#include<bits/stdc++.h>

using namespace std;

#define gc getchar
#define pc putchar

bool vis[100005];
int f[100005],n,t,cnt1=0;

//set<int> st;

void scan(int *x)
{
	register char c = getchar();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar());
	for(; (c>47)&&(c<58);c = getchar())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}

void printint(long long n)
{
	if(n == 0)
	{
		putchar('0');
		putchar('\n');
	}
	else if(n == -1)
	{
		putchar('-');
		putchar('1');
		putchar('\n');
	}
	else
	{
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while(n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while(buf[i] != '\n')
			putchar(buf[++i]);
	}
}

main()
{
   ios_base::sync_with_stdio(0);
   scan(&t);
   while(t--)
   {
     scan(&n);
     int a[n+1],i,j,cnt=0;
     for(i=1;i<=n;i++) f[i]=0;
     for(i=1;i<=n;i++)
     {
       scan(&a[i]);
       f[i] = (i+a[i])%n+1;
     }
     for(i=1;i<=n;i++)
     {
       memset(vis,false,sizeof(vis));
       j=f[i];
       while(1)
       {
         vis[j]=true;
         j=f[j];
         if(j==i) {cnt++;break;}
         else if(vis[j]==true) break;
       }
     }
     printint(cnt);
   }
}
