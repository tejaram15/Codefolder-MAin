#include<bits/stdc++.h>
using namespace std;
#define pc putchar
#define gc getchar
 
const int mx = 400000;
 
/***************************************/
inline void scanint(int *x)
{
	register char c = gc();
	*x = 0;
	for(; (c<48)||(c>57);c = gc());
	for(; (c>47)&&(c<58);c = gc())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
 
inline void printint(int n)
{
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
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while(n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while(buf[i] != '\n')
			pc(buf[++i]);
	}
}
/****************************************************/
 
 
typedef struct mul
{
  int two;
  int five;
}mul;
 
static const mul empty = { 0 , 0 };
 
void Factors(int n,int &two,int &five)
{
  while (n%2 == 0)
  {
    two++;
    n = n/2;
  }
  for (int i = 3; i <= sqrt(n) ; i = i+2)
  {
    if(i>5) break;
    while (n%i == 0)
    {
      if(i==5) five++; 
      n = n/i;
    }
  }
  if (n==5) five++;
}
 
mul tree[mx] = {0,0} ;
mul lazy[mx] = {0,0} ;
int a[mx];
 
//Here build is 0-indexed i.e.2*i+1 -> left child and 2*i+2 ->right
void build(int node,int start,int end)
{
  if(start==end)
  {
    Factors(a[start],tree[node].two,tree[node].five);
    return;
  }
  int mid = (start + end) / 2 ;
  build(2*node+1,start,mid);
  build(2*node+2,mid+1,end);
  tree[node].two = tree[2*node+1].two + tree[2*node+2].two;
  tree[node].five = tree[2*node+1].five + tree[2*node+2].five;
}
 
//range_query again 0-Based
mul range_query(int node,int start,int end,int l,int r)
{
  if(l>end || r<start) return empty;
   if(lazy[node].two!=0||lazy[node].five!=0)
   {
     tree[node].two += lazy[node].two;
     tree[node].five += lazy[node].five;
     if(start!=end)
     {
       lazy[2*node+1].two += lazy[node].two;
       lazy[2*node+1].five += lazy[node].five;
       lazy[2*node+2].two += lazy[node].two;
       lazy[2*node+2].five += lazy[node].five;
     }
    lazy[node]=empty;
   }
  if(l<=start && r>=end) return tree[node];
  int mid = (start + end) / 2 ;
  mul p1 = range_query(2*node+1,start,mid,l,r);
  mul p2 = range_query(2*node+2,mid+1,end,l,r);
  p1.two += p2.two;
  p1.five += p2.five;
  return p1;
}
 
//Range update for type - 1
void update(int node,int start,int end,int l,int r,int x)
{
   if(lazy[node].two!=0||lazy[node].five!=0)
   {
     tree[node].two += lazy[node].two;
     tree[node].five += lazy[node].five;
     if(start!=end)
     {
       lazy[2*node+1].two += lazy[node].two;
       lazy[2*node+1].five += lazy[node].five;
       lazy[2*node+2].two += lazy[node].two;
       lazy[2*node+2].five += lazy[node].five;
     }
    lazy[node]=empty;
   }
  if(start>end || end<l || r<start) return;
  if(start>=l && end<=r) 
  {
    mul temp = empty;
    Factors(x,temp.two,temp.five);
    tree[node].two += temp.two;
    tree[node].five += temp.five;
    if(start!=end)
    {
         lazy[2*node+1].two += temp.two;
         lazy[2*node+1].five += temp.five;
         lazy[2*node+2].two += temp.two;
         lazy[2*node+2].five += temp.five;
    }       
    return;
  }
  int mid = (start + end) / 2 ;
  update(2*node+1,start,mid,l,r,x);
  update(2*node+2,mid+1,end,l,r,x);
  tree[node] = empty;
  tree[node].two = tree[2*node+1].two + tree[2*node+2].two;
  tree[node].five = tree[2*node+1].five + tree[2*node+2].five;    
}
 
//range update for type - 2
void update2(int node,int start,int end,int l,int r,int y,int val)
{
  if(start>end || end<l || r<start) return;
  if(start==end) 
  {  
    mul temp = empty,temp1 = empty;
    int x =  ( (start+1) - (l+1) + 1 );
    Factors(x,temp.two,temp.five);
    Factors(y,temp1.two,temp1.five);
    temp.two += temp1.two;
    temp.five += temp1.five;
    tree[node] = temp;val++;
    return; 
  }                           

  int mid = (start + end) / 2 ;
  update2(2*node+1,start,mid,l,r,y,val);
  update2(2*node+2,mid+1,end,l,r,y,val);
  tree[node] = empty;
  tree[node].two = tree[2*node+1].two + tree[2*node+2].two;
  tree[node].five = tree[2*node+1].five + tree[2*node+2].five;    
}
 
main()
{
  int t;
  scanint(&t);
  while(t--)
  {
    memset(&tree,0,sizeof tree);
    memset(&lazy,0,sizeof lazy);
    int n,m;
    scanint(&n);
    scanint(&m);
    for(int i=0;i<n;i++) scanint(&a[i]);
    build(0,0,n-1);
    //for(int i=0;i<2*n-1;i++) {cout<<"tree["<<i<<"] = "<<tree[i].two<<" - "<<tree[i].five<<"\n";} 
    int type,l,r,ans = 0;
    for(int i=0;i<m;i++)
    {
	scanint(&type);
	scanint(&l);
	scanint(&r);
	if(type == 3)
	{
	  mul x = range_query(0,0,n-1,l-1,r-1);
	  //cout<<"ans : ";
	  //printint(min(x.two,x.five));
	  // cout<<"\n After rq : \n";
	  // for(int i=0;i<2*n;i++) {cout<<"tree["<<i<<"] = "<<tree[i].two<<" - "<<tree[i].five<<"\n";}
           ans += min(x.two,x.five);
	}
	else if(type == 1)
	{
	   int x;
	   scanint(&x);
	   update(0,0,n-1,l-1,r-1,x);
	   //cout<<"\n After type 1 : \n";
	   //for(int i=0;i<2*n;i++) {cout<<"tree["<<i<<"] = "<<tree[i].two<<" - "<<tree[i].five<<"\n";}
	}
	else if(type == 2)
	{
	   int y;
	   scanint(&y);
	   update2(0,0,n-1,l-1,r-1,y,l);
	   //cout<<"\n After type 2 : \n";
	   //for(int i=0;i<2*n;i++) {cout<<"tree["<<i<<"] = "<<tree[i].two<<" - "<<tree[i].five<<"\n";}
	}
    }
    printint(ans);
  }
} 