// Find longest common subsequence, 1<= |S1|,|S2|<=10^5 .
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

int n, m;
string s1, s2;
int dp[1001][1001];

int rec(int l1, int l2){
   // Base case
   if (l1 >= n || l2 >= m) return 0;

   // Memoization
   if (dp[l1][l2] != -1)
      return dp[l1][l2];

   int ans = max(rec(l1+1, l2), rec(l1, l2+1));
   if(s1[l1] == s2[l2]){
      return ans = max(ans, rec(l1+1, l2+1)+1);
   }   
   return dp[l1][l2] = ans;   
}

void solve(){
   cin >> n >> m;
   cin >> s1 >> s2;
   memset(dp, -1);
   cout << rec(0, 0)<<"\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}