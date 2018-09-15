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
LL ans[MXN];
int main(void){
  int t; scanf("%d", &t);
  while(t--){
    LL x; int n; scanf("%lld %d", &x, &n);
    if(n == 1){
      printf("%lld\n", x); continue;
    }
    rep1(i, 1, n+1) ans[i] = 0;
    rep1(i, 1, n+1){
      ans[i]++;
      if(!(--x)) break;
    }
    LL t = x / (n-1);
    x %= (n - 1);
    rep1(i, 2, n) ans[i] += t;
    ans[1] += (t + 1) / 2; ans[n] += t / 2;
    int p = n;
    if(t % 2) p = 1;
    if(p == n){
      rep(i, x){
        p--; ans[p]++;
      }
    }
    else{
      rep(i, x){
        p++; ans[p]++;
      }
    }
    rep1(i, 1, n+1) printf("%lld%c", ans[i], " \n"[ i == n] );
  }
  return 0;
}
