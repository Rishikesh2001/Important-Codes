/*Find maximum sum subarray. N <= 10^5*/

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

int n;  
int dp[100001];
int a[100001];

int rec(int level){
   if(level == 0) return a[0];

   dp[level] = max(a[level], rec(level-1) + a[level]);
   return dp[level];
}

void solve(){
   cin >> n;
   for(int i=0; i<n; i++){
      cin >> a[i];
   }
   memset(dp, 0, sizeof(dp));
   rec(n-1);
   cout << *max_element(dp, dp+n) <<"\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}