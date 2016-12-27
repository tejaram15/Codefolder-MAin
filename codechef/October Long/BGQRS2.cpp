#include<bits/stdc++.h>
using namespace std;
#define lsone(i) (i&(-i))

struct mul
{
int two = 0,five = 0;
mul(){two=0;five=0;}
};


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

class ftree
{
private:
vector<mul> ft;
public:
ftree(int n) {ft.resize(n+1);}
};


main()
{
ftree obj(5);
}