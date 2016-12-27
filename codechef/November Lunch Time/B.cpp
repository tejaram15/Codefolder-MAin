#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)

const int MAXN = (int) 1e6 + 10;
int n, a[MAXN], prime[MAXN], cntPrimes[MAXN], taken[MAXN];
vector<int> primeDivs[MAXN];

const int MAX = (int) 1e6;
const int MAXA = (int) 1e6;

int main() {
  FOR(i, 2, MAXN) prime[i] = true;
  FOR(i, 2, MAXN) if (prime[i]) for (int j = i + i; j < MAXN; j += i) {
    prime[j] = false; 
  } 
  FOR(i, 2, MAXN) if (prime[i]) for (int j = i; j < MAXN; j += i) {
    int cnt = 0, val = j;
    while (val % i == 0) {
      val /= i;
      cnt++;
    }
    if (cnt % 2 == 1) primeDivs[j].push_back(i);
  }
  cerr << "preprocessing done" << endl;
  /*
  FOR(i, 1, 10) {
    cerr << "i " << i << endl;
    for (auto x : primeDivs[i]) cerr << x << " "; cerr << endl;
  } 
  */
  int T, sumN = 0;
  scanf("%d", &T);
  assert(T >= 1 && T <= MAX);
  while (T--) {
    scanf("%d", &n);
    assert(n >= 1 && n <= MAX);
    sumN += n;

    vector<int> vals;
    REP(i, n) {
      scanf("%d", &a[i]);
      assert(a[i] >= 1 && a[i] <= MAXA);

      for (int d : primeDivs[a[i]]) {
        cntPrimes[d]++;
        vals.push_back(d);
      }
    }

    int ans = 0;
    for (auto x: vals) if (!taken[x] && prime[x]) {
      ans += min(cntPrimes[x], n - cntPrimes[x]);
      taken[x] = true;
    }

    printf("%d\n", ans);
    
    for (auto x: vals) {
      taken[x] = false;
      cntPrimes[x] = 0;
    }
  }

  assert(sumN <= MAX);
  
  return 0;
}