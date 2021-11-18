/*You can see N stars in the sky. You know the coordinates and the brightness of the stars. The maximum brightness of any star can be C. If at moment M, a star has brightness S, then at moment M+1, the star will have brightness S+1, if S+1 <= C, otherwise 0. You look at the sky Q times, you want to know the total brightness of the stars lying in the viewed rectangle, with the lower-left corner (X1i, Y1i) and upper right corner (X2i, Y2i) at moment Mi.
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

int n, q, c;
int a[101][101][11];
int dp[101][101][11];

int recur(int x, int y, int s){
   if(x == 0 || y == 0) return 0;

   if(dp[x][y][s] != -1) return dp[x][y][s];
   
   return dp[x][y][s] = (recur(x-1,y,s) + recur(x,y-1,s) - recur(x-1,y-1,s) +a[x][y][s]); 
}

void solve(){
   cin >> n >> q >> c;

   for(int s=0; s<=c; s++){
      for(int i=0; i<=100; i++){
         for(int j=0; j<=100; j++){
            if(i==0 || j==0){
               dp[i][j][s] = 0;
            } else{
               dp[i][j][s] = -1;
            }

            a[i][j][s] = 0;
         }
      }
   }


   for(int i=1; i<=n; i++){
      int x, y, s;
      cin >>x >>y >>s;
      a[x][y][s]++;
   }

   for(int i=0; i<=c; i++){
      recur(100, 100, i);
   }


   while(q--){
      ll ans = 0;
      ll m, x1, y1, x2, y2;
      cin >> m >> x1 >> y1 >> x2 >> y2;

      for(int s=0; s<=c; s++){
         ll curr_bright = (s+m) % (c+1);
         ans += (dp[x2][y2][s] - dp[x1-1][y2][s] - dp[x2][y1-1][s] + dp[x1-1][y1-1][s])* curr_bright;
      }
      cout << ans << "\n";
   }
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int test;cin >> test;while(test--)
   solve();
}



/*
2
3 2 3
1 2 1
1 3 0
2 3 3
1 1 3 3 3
2 1 1 1 4
2 3 5
3 3 2
1 1 4
0 1 1 5 5
2 1 1 2 3
3 1 1 3 3
*/