// Knapsack with additional constraints to the no. of items taken.
// i.e you can take weights <= w and no. of items <=k
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

int n, k, w;
vector <pair<int, int>> a;
int dp[501][501][501];

int rec(int level, int leftk, int leftw){
   // Pruning
   if (leftk<0 || leftw<0) return -1e9;
   // Base Case
   if (level == n){
      return 0;
   }

   // Memoization
   if(dp[level][leftk][leftw] != -1)
      return dp[level][leftk][leftw];

   int ans = max(rec(level+1, leftk, leftw), a[level].S+rec(level+1, leftk-1, leftw-a[level].F));

   return dp[level][leftk][leftw] = ans;
}

void solve(){
   cin>>n>>k>>w;
   a.resize(n);
   for(int i=0; i<n; i++){
      cin>>a[i].F>>a[i].S;
   }
   memset(dp, -1, sizeof(dp));
   cout<<rec(0, k, w)<<"\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}