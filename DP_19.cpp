/*You are given a string S of length N. You have to find the minimum number of characters you should change in S so that there will be a substring of length K in S that is also a substring of the infinite string "RGBRGBRGB ...".

For each test case, print the minimum number of characters you should change in S so that there will be a substring of length K in S that is also a substring of the infinite string "RGBRGBRGB ...".
*/
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

int n, k;
string s;
ll dp[100101][3];

// 0 --> red, 1 --> green, 2 --> blue
ll recur(int level, int color){
   if(level > n) return 0;

   if(dp[level][color] != -1) return dp[level][color];

   if(color == 0){
      if(s[level-1] == 'R') return dp[level][color] = recur(level+1, color+1);
      else return dp[level][color] = recur(level+1, color+1) +1;
   } else if(color == 1){
      if(s[level-1] == 'G') return dp[level][color] = recur(level+1, color+1);
      else return dp[level][color] = recur(level+1, color+1) +1;
   } else{
      if(s[level-1] == 'B') return dp[level][color] = recur(level+1, 0);
      else return dp[level][color] = recur(level+1, 0) +1;
   }
}

void solve(){
   cin >> n >> k;
   cin >> s;
   
   for(int i=0; i<=n; i++){
      for(int j=0; j<3; j++){
         dp[i][j] = -1LL;
      }
   }

   dp[0][0] = dp[0][1] = dp[0][2] = 0LL;
   dp[n+1][0] = dp[n+1][1] = dp[n+1][2] = 0LL;
   recur(1, 0); recur(1, 1); recur(1, 2);

   ll ans = (int)1e9;
   for(int i=1; i<=n-k+1; i++){
      for(int j=0; j<3; j++){
         ans = min(ans, dp[i][j] - dp[i+k][(j+k)%3]);
      }
   }
   cout << ans << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int test;cin >> test;while(test--)
   solve();
}