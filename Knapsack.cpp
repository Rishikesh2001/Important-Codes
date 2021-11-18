#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define mod 1000000007
typedef long long int ll;
typedef long double ld;
using namespace std;

int n, w;
vector<pair<int, int>> a;
int dp[1001][1001];

int rec(int level, int weightLeft){
   if (weightLeft < 0) return -1e9;
   
   if (level == n) return 0;

   if (dp[level][weightLeft] != -1){
      return dp[level][weightLeft];
   }

   int ans = max(rec(level+1, weightLeft), a[level].S+rec(level+1, weightLeft-a[level].F));

   return dp[level][weightLeft] = ans;  
}

void solve(){
   cin >> n >> w;
   a.resize(n);

   for(int i=0; i<n; i++){
      cin >> a[i].F >> a[i].S;
   }

   memset(dp, -1, sizeof(dp));
   cout << rec(0, w) << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}