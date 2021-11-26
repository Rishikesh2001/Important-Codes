/*Given an array of N integers, find the length of the smallest sub-array that contains all the distinct elements of the array.
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
int a[100100];
int freq[1001000];

void solve(){  
   cin >> n;
   int cntDistinct = 0;
   for(int i=0; i<n; i++){
      cin >> a[i];
      if(freq[a[i]] == 0){
         cntDistinct++;
      }
      freq[a[i]]++;
   }
   memset(freq, 0);
   
   int tail = 0, head = -1;
   int ans = 1e9;
   while(tail < n){
      while(head+1 < n && cntDistinct > 0){
         head++;
         if(freq[a[head]] == 0){
            cntDistinct--;
         }
         freq[a[head]]++;
      }

      if(cntDistinct == 0)
      ans = min(ans, head-tail+1);

      if(head >= tail){
         if(freq[a[tail]] == 1){
            cntDistinct++;
         }
         freq[a[tail]]--;
         tail++;
      } else{
         tail++;
         head = tail - 1;
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

/*Input
6
5
1 1 3 2 3
5
1 2 3 4 5
6
1 2 2 3 3 4
6
1 2 1 3 2 4
5
1 1 1 1 1
1
1

Output
3
5
6
4
1
1
*/
