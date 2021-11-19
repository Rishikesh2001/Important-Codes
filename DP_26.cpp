/*You are given N marbles in different colours. You have to remove marbles till there are no marbles left. Each time you can choose continuous marbles with the same color, remove them and get k*k points (where ‘k’ is the length of the continuous marbles removed). Find the maximum points you can get.
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

int n;
int dp[101][101][101];
int a[101];

int recur(int l, int r, int carry){
   if(l > r) return 0;
   if(l == r) return (carry+1)*(carry+1);

   if(dp[l][r][carry]!= -1) return dp[l][r][carry];

   // Initializing ans bcoz  at start this could be the potential value.
   int ans = (carry+1)*(carry+1) + recur(l+1, r, 0);
   for(int i=l+1; i<=r; i++){
      if(a[i] == a[l]){
         ans = max(ans, recur(i, r, carry+1) + recur(l+1, i-1, 0));
      }
   }

   return dp[l][r][carry] = ans;
}

void solve(){
   cin >> n;
   for(int i=0; i<n; i++){
      cin >> a[i];
   }

   for(int i=0; i<=100; i++){
      for(int j=0; j<=100; j++){
         for(int k=0; k<=100; k++){
            dp[i][j][k] = -1;
         }
      }
   }

   cout << recur(0, n-1, 0) << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}