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
vector<PII>edge[MXN];
int dp[20][MXN], dep[MXN];
PII val[20][MXN];
void dfs(int u, int pa, int dpt, int v){
  dep[u] = dpt;
  dp[0][u] = pa;
  val[0][u] = MP(v, v);
  for(PII x : edge[u]){
    if(pa == x.F){
      val[0][u].S += x.S; 
      continue;
    }
    dfs(x.F, u, dpt+1, x.S);
  }
  return ;
}
int go(int v, int dpt, PII &re){
  rep(i, 18){
    if(dpt & (1<<i)){
      re.F += val[i][v].F;
      re.S += val[i][v].S;
      v = dp[i][v];
    }
  }
  return v;
}
int lca(int u, int v){
  PII v1 = MP(0, 0), v2 = MP(0, 0);
  int su = u, sv = v;
  if(dep[u] > dep[v]) u = go(u, dep[u] - dep[v], v1);
  if(dep[v] > dep[u]) v = go(v, dep[v] - dep[u], v2);
  if(u == v){
    if(su != u) return v1.F;
    else return v2.S - v2.F;
  }
  per1(i, 18, 0){
    if(dp[i][u] == dp[i][v]) continue;
    v1.F += val[i][u].F; v1.S += val[i][u].S;
    v2.F += val[i][v].F; v2.S += val[i][v].S;
    u = dp[i][u], v = dp[i][v];
  }
  v1.F += val[0][u].F; v1.S += val[0][u].S;
  v2.F += val[0][v].F; v2.S += val[0][v].S;

  return v1.F + (v2.S - v2.F); 
}
int main(void){
  int t; scanf("%d", &t);
  while(t--){
    int n; scanf("%d", &n);
    int sum = 0;
    rep1(i, 1, n+1) edge[i].clear();
    rep1(i, 1, n){
      int u, v, c1, c2;
      scanf("%d %d %d %d", &u, &v, &c1, &c2);
      sum += c1 + c2;
      edge[u].pb( MP(v, c1) );
      edge[v].pb( MP(u, c2) );
    }
    dfs(1, 0, 1, 0);
    rep1(i, 1, 18) rep1(j, 1, n+1){
      dp[i][j] = dp[i-1][ dp[i-1][j] ];
      val[i][j].F = val[i-1][j].F + val[i-1][dp[i-1][j]].F;
      val[i][j].S = val[i-1][j].S + val[i-1][dp[i-1][j]].S;
    }
    int q; scanf("%d", &q);
    while(q--){
      int u, v; scanf("%d %d", &u, &v);
      int ans = sum - lca(u, v);
      printf("%d\n", ans);
    }
  }
  return 0;
}
