#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <locale>
using namespace std;
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define MS0(I) memset(I, 0, sizeof(I));
#define MS1(I) memset(I, -1, sizeof(I));
#define DRI(A) int A; scanf("%d", &A);
#define DRII(A, B) int A, B; scanf("%d %d", &A, &B);
#define DRIII(A, B, C) int A, B, C; scanf("%d %d %d", &A, &B, &C);
#define DRL(A) LL A; scanf("%lld", &A);
#define DRLL(A, B) LL A, B; scanf("%lld %lld", &A, &B);
#define DRLLL(A, B, C) LL A, B, C; scanf("%lld %lld %lld", &A, &B, &C);
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define rep(i, n) for(int i = 0; i < n; i ++)
#define rep1(i, a, b) for(int i = a; i < b; i ++)
#define per1(i, a, b) for(int i = a; i >= b; i --)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long LL;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<LL, LL> PLL;
//////////////////////
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const long long INFF = (long long)1e18;
const int mod = (int)1e9 + 7;
const int MXN = (int)1e5 + 7;
LL a[MXN];
LL val[MXN];
LL mypow(LL v, LL t){
  LL res = 1;
  while(t){
    if(t & 1) res = res*v%mod;
    v = v*v%mod;
    t >>= 1;
  }
  return res;
}
void build(){
  val[0] = 1;
  rep1(i, 1, MXN) val[i] = mypow(i, mod-2);
}
int main(void){
  int t; scanf("%d", &t);
  build();
  while(t--){
    int n; scanf("%d", &n);
    rep1(i, 1, n+1) scanf("%lld", a + i);
    LL ans = 0, v = 1;
    rep1(i, 1, n+1) v = v*a[i]%mod;
    rep1(i, 1, n+1){
      ans = (ans + v*val[a[i]]%mod*(a[i]-1)) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
