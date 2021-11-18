/*You are given an array A of size N. In one operation you can select any non-decreasing
subarray and increment all the elements in the subarray by one. Your goal is to make the
whole array non-decreasing in minimum operations.
*/
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
typedef long long int ll;
using namespace std;

void solve(){
   int n; cin>>n;
   int a[n];

   int sum = 0;
   for (int i=0; i<n; i++){
      cin>>a[i];

      if (i && a[i-1]>a[i]){
         sum += (a[i-1]-a[i]);
      }
   }

   cout << sum << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int test; cin>>test; while(test--)
   solve();
}