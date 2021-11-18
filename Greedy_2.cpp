#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define mod 1000000007
typedef long long int ll;
using namespace std;

void solve(){
   int n, k; 
   cin>>n>>k;

   vector<int> a(n);
   int ans = 0;
   for(int i =0; i< n; i++){
      cin >> a[i];
      if(a[i]>k && a[i]!=1){
         ans += min(a[i] % k, k - a[i] % k);
      } else{
         ans += (k-a[i]);
      }
   }

   cout << ans << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}