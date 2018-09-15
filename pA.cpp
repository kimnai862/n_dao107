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
pair<PII, LL>a[MXN];
LL lsum[MXN];
int main(void){
  int t; scanf("%d", &t);
  while(t--){
    int n, k; scanf("%d %d", &n, &k);
    rep1(i, 1, n+1) scanf("%d %d %lld", &a[i].F.F, &a[i].F.S, &a[i].S);
    sort(a + 1, a  + n + 1);
    rep1(i, 1, n+1) lsum[i] = lsum[i-1] + a[i].S*(a[i].F.S - a[i].F.F + 1);
    LL ans = 0;
    rep1(i, 1, n+1){
      if(a[i].F.S - a[i].F.F + 1 >= k){
        ans = max(ans, a[i].S*k);
        continue;
      }
      int r = a[i].F.F + k - 1;
      int ll = i, rr = n, ok = ll;
      while(ll <= rr){
        int mid = (ll + rr) >> 1;
        if(a[mid].F.S <= r) ll = mid + 1, ok = mid;
        else rr = mid - 1;
      }
      LL val = lsum[ok] - lsum[i-1];
      if(ok != n && r >= a[ok+1].F.F){
        val += a[ok+1].S*(r - a[ok+1].F.F + 1);
      }
      ans = max(ans, val);
    }
    rep1(i, 1, n+1){
      if(a[i].F.S - a[i].F.F + 1 >= k) continue;
      int l = a[i].F.S - k + 1;
      int ll = 1, rr = i, ok = rr;
      while(ll <= rr){
        int mid = (ll + rr) >> 1;
        if(a[mid].F.F >= l) rr = mid - 1, ok = mid;
        else ll = mid + 1;
      }
      LL val = lsum[i] - lsum[ok-1];
      if(ok != 1 && l <= a[ok-1].F.S){
        val += a[ok-1].S*(a[ok-1].F.S - l + 1);
      }
      ans = max(ans, val);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

