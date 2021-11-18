/*Android mobile unlock pattern is a grid of 3 x 3 cells, where drawing a specific pattern connecting a specific sequence of cells in order will unlock the android mobile.
Given a number n, your task is to find the number of android unlock patterns connecting exactly n cells.
Rules of a valid pattern:

1. Each pattern must connect exactly n cells.
2. All the cells must be distinct.
3. If the line connecting two consecutive cells in the pattern passes through any other cells, the other cells must have previously selected in the pattern. No jumps through the non-selected cell is allowed.
4. The order of cells used matters.

Sample Input 1
1 
Sample Output 1
9

Sample Input 2
2
Sample Output 2
56
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
int visit[10];
int skip[10][10];

int solve(int curr, int rem){
   // Base case
   if(!rem) return 1;

   visit[curr] = 1;
   ll ans = 0;
   for(int i=1; i<=9; i++){
      if(!visit[i] && (!skip[curr][i] || visit[skip[curr][i]]))
         ans += solve(i, rem-1);
   }

   // Revert changes
   visit[curr] = 0;
   return ans;
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin>>n;
   skip[1][3] = skip[3][1] = 2;
   skip[1][7] = skip[7][1] = 4;
   skip[9][3] = skip[3][9] = 6;
   skip[7][9] = skip[9][7] = 8;
   skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8]= skip[8][2] = skip[4][6] = skip[6][4] =5;
   
   //int test;cin >> test;while(test--)
   ll ans =0;
   ans += solve(1, n-1)*4;
   ans += solve(2, n-1)*4;
   ans += solve(5, n-1);

   cout << ans << "\n";
}
