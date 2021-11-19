/*Let N be a positive odd number.
There are N coins, numbered 1,2,…,N. For each i (1≤i≤N), when Coin i is tossed,
it comes up heads with probability pi and tails with probability 1−pi.

Taro has tossed all the N coins. Find the probability of having more heads than tails.*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define memset(x, value) memset(x, value, sizeof(x))
#define mod 1000000007
typedef long long int ll;
typedef long double ld;
using namespace std;

void solve(){
   int n;
   cin >> n;

   double a[n], dp[n+1][n+1];
   for(int i=0; i<n; i++){
      cin >> a[i];
   }

   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         dp[i][j] = 0.0;
      }
   }
   dp[0][0] = 1.0;

   for(int i=1; i<=n; i++){
      for(int j=0; j<=i; j++){
         if (j == 0)
            dp[i][j] = dp[i-1][j]*(1-a[i-1]);
         else
            dp[i][j] = (a[i-1])*dp[i-1][j-1] + (1-a[i-1])*dp[i-1][j]; 
      }
   }

   double ans = 0;
   for(int i=n/2+1; i<=n; i++){
      ans += dp[n][i];
   }
   cout << ans << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}