/*Calculating 2D prefix using dp(recursive method)*/
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

int dp[1001][1001];

int recur(int i, int j){
   if(i == 0 || j==0) return 0;

   if(dp[i][j] != 1) return dp[i][j];
   return dp[i][j] = recur(i-1, j) + recur(i, j-1) - recur(i-1, j-1) + dp[i][j];
}

void solve(){
   int n; cin>>n;
   memset(dp, 0);
   for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
         cin >> dp[i][j];
      }
   }

   recur(n, n);
   for(int i=0; i<=n; i++){
      for(int j=0; j<=n; j++){
         cout << dp[i][j] << " ";
      }
      cout << "\n";
   }

}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}