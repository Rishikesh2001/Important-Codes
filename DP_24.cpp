/*You are given a colourful array of N elements. It can have M different colours, some of the elements are uncoloured. The beauty of the array is defined as the minimum number of contiguous groups you can split the array into so that each group contains elements of the same colour. You have to colour the uncoloured elements of the array such that the beauty of the array is K. To colour the i-th element with colour j, you will require Pij liters of paint. You have to find the minimum amount of paint (in liters) needed to finish the job.

For each test case, print the minimum amount of paint (in liters) needed to finish the job. If there is no valid way to colour the array with beauty K, print  - 1.
*/
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define memset(x, value) memset(x, value, sizeof(x))
#define mod 1000000007
typedef long double ld;
using namespace std;

int n, m, k;
int dp[101][101][101];
int cost[101][101];
int a[101];

int recur(int level, int k, int prev){
   if(k < 0) return (int)1e18;
   if(level > n){
      if(k == 0) return 0;
      else return (int)1e18;
   }

   if(dp[level][k][prev] != -1) return dp[level][k][prev];

   if(a[level] != 0){
      return dp[level][k][prev] = recur(level+1, k-(prev!=a[level]), a[level]);
   }
   else{
      int ans = (int)1e18;
      for(int i=1; i<=m; i++){
         ans = min(ans, recur(level+1, k-(prev!=i), i) + cost[level][i]);
      }
      return dp[level][k][prev] = ans;
   }
}

void solve(){
   cin >> n >> m >> k;

   for(int i=1; i<=n; i++){
      cin >> a[i];
   }

   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
         cin >> cost[i][j];
      }
   }

   for(int i=0; i<=100; i++){
      for(int j=0; j<=100; j++){
         for(int k=0; k<=100; k++){
            dp[i][j][k] = -1;
         }
      }
   }
 
   recur(1, k, 0) < 1e18 ? cout << recur(1, k, 0) << "\n" : cout << "-1\n"; 
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int test;cin >> test;while(test--)
   solve();
}

/*
Input:
3
1 3 1
0    
3 4 1
1 1 1
1    
5    
3 2 1
1 2 1
1 2  
3 4  
5 6

Output:
1
0
-1
*/