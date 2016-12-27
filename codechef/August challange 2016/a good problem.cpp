//Coded by
	//-Ram
//segment tree will be used
#include<bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vii;

class STree
{
  private:
  int n;
  vi st,A;
  int left(int p) {return p<<1;}
  int right(int p) {return (p<<1)+1;}

  void build(int p,int l,int r)
  {
    if(l==r) st[p]=l;
    else
    {
      build(left(p),l,(l+r)/2);
      build(right(p),(l+r)/2+1,r);
      int p1=st[left(p)],p2=st[right(p)];
      st[p]= (A[p1] > A[p2]) ? p1 : p2;
    }
  }

  int rmq(int p,int l,int r,int i,int j)
  {
    if(i>r||j<l) return -1;
    if(l>=i&&r<=j) return st[p];
    int p1=rmq(left(p),l,(l+r)/2,i,j);
    int p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return (A[p1] > A[p2]) ? p1 : p2;
   }

  public:
   STree(const vi &_A)
   {
     A= _A; n=(int) A.size();
     st.assign(4*n,0);
     build(1,0,n-1);
   }
   int rmq(int i,int j) {return rmq(1,0,n-1,i,j);}
};

main()
{
   ios_base::sync_with_stdio(0);
   int n;
   cin>>n;
   int a[n+1],sum=0;
   for(int i=0;i<n;i++) cin>>a[i];
   vi A(a,a+n);
   STree st(A);
   vii pre;
   for(int i=0;i<n;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(i<j)
       {
       int f=a[i]&a[j];
       if(f^a[i]==0||f^a[j]==0)
         sum+=a[st.rmq(i,j)];
       }
     }
   }

   cout<<sum;
}
