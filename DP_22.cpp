/*Ugly numbers. It's a simple recursive method*/
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
int in_2, in_3, in_5;
int dp[100100];

void recur(int level, int next_2, int next_3, int next_5){
   if(level == n) return ;

   int num = min(next_2, min(next_3, next_5));
   dp[level] = num;
   if(num == next_2){
      in_2++;
      next_2 =dp[in_2]*2; 
   } 
   if(num == next_3){
      in_3++;
      next_3 =dp[in_3]*3;
   } 
   if(num == next_5){
      in_5++;
      next_5 =dp[in_5]*5;
   }
   recur(level+1, next_2, next_3, next_5);
}

void solve(){
   cin >> n;
   memset(dp, -1);
   dp[0] = 1;
   recur(1, 2, 3, 5);
   cout << dp[n-1]<<"\n";

   for(int i=0; i<n; i++){
      cout << dp[i] << " ";
   }
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}