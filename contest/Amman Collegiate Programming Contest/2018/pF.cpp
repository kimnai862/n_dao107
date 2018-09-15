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
const int MXN = (int)1e6 + 7;
int in[MXN], a[MXN];
vector<int>pr[MXN];
void build(){
  rep1(i, 1, MXN){
    for(int j = i; j < MXN; j += i)
      pr[j].pb(i);
  }
  return ;
}
int main(void){
  int t; scanf("%d", &t);
  build();
  int cntp = 0;
  while(t--){
    cntp++;
    int n; scanf("%d", &n);
    rep1(i, 1, n+1) scanf("%d", a + i);
    rep1(i, 1, n+1) in[ a[i] ] = cntp;
    LL ans = 0;
    rep1(i, 1, n+1){
      for(int v : pr[a[i]]){
        if(in[v] == cntp){
          ans += v; break;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
