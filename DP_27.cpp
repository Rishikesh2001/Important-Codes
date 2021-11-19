/*Given an array of positive integers. Count the number of all bitonic sequences possible such that the absolute difference of any adjacent elements is <= K. Print ans modulo 1e9+7.
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

int n, k;
int a[1001];
int dp[1001][1001][2];

int comp(int a, int b){
   if(a > b) return 1;
   return 0;
}

//Here, "level" is the current element to be placed, "side" is the index of element of side which is equal to level-1 and "other" is the index of element of the other side.
int recur(int level, int other, int side){
   if(level == n) return 1;

   if(dp[level][other][side] != -1) return dp[level][other][side];

   int ans = 0;
   if(side == 1){
      if(a[other] - a[level]<= k){
         ans += recur(level+1, level-1, 0);
      } 
      if(a[level-1] - a[level] <= k){
         ans += recur(level+1, other, 1);
      }
   } 
   else {
      if(a[other] - a[level]<= k){
         ans += recur(level+1, level-1, 1);
      } 
      if(a[level-1] - a[level] <= k){
         ans += recur(level+1, other, 0);
      }
   }

   return dp[level][other][side] = ans % mod;
}

void solve(){
   cin >> n >> k;
   for(int i=0; i<n; i++){
      cin >> a[i];
   }
   sort(a, a+n, comp);
   memset(dp, -1);
   
   int ans = recur(1, 0, 1);
   
   if(ans <= 0) cout << "0\n";
   else cout << (ans - 2 + mod) % mod << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int test;cin >> test;while(test--)
   solve();
}

/*
Input:
2
4 6
10 4 1 5
9 44
96 29 21 90 46 77 31 63 79

Output:
4
126
*/