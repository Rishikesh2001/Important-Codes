/*Find the longest palindromic substring. 1<=len(string)<= 1000. For multiple test cases uncomment the test cases line. It is an O(N^2 + N) algorithm where N is the length of the string.
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

int dp1[1001][1001];
int dp2[1001];
string s;

int palindrome(int l, int r){
   if(l >= r) return 1;

   if(dp1[l][r] != -1) return dp1[l][r];

   if(s[l] == s[r]) return dp1[l][r] = palindrome(l+1, r-1);
   else return dp1[l][r] = 0;
}

int recur(int i){
   if(i < 0) return 0;

   if(dp2[i] != -1) return dp2[i];

   int ans = 1e9;
   for(int j=i; j>=0; j--){
      if(palindrome(j, i)){
         ans = min(ans, j);
         recur(i-1);
      } 
   }

   return dp2[i] = ans;
}

void solve(){
   cin >> s;
   memset(dp1, -1);
   memset(dp2, -1);

   recur(s.length()-1);
   // for(int i=0; i<s.length(); i++){
   //    cout << dp2[i] << " ";
   // }

   // cout << "\n";

   int index, max_len=0;
   for(int i=0; i<s.length(); i++){
      if(max_len < i-dp2[i]+1){
         max_len = i-dp2[i]+1;
         index = dp2[i];
      }
   }
   
   cout << s.substr(index, max_len) << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}