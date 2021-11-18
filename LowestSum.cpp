#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define mod 1000000007
typedef long long int ll;
typedef long double ld;
using namespace std;

void solve(){
   int k, q;
   cin >> k >> q;

   ll a[k], b[k];
   for (int i = 0; i < k; i++){
      cin >> a[i];
   }
   
   for (int i = 0; i < k; i++){
      cin >> b[i];
   }
   sort(a, a+k); sort(b, b+k);

   ll cnt;
   while(q--){
      int x; cin>>x;
      ll low = a[0] + b[0];
      ll high = a[k - 1] + b[k - 1];
      ll ans = low;
      while(low <= high){
         ll mid = (low+high)/2;

         cnt = 0;
         for (int i = 0; i < k; i++){
            ll temp = upper_bound(b, b+k, mid - a[i]) - b;
            cnt += temp;
         }
         
         if (cnt >= x){
            ans = mid;
            high = mid - 1;
         } else{
            low = mid + 1;
         }
      }
      cout << ans <<"\n";
   }
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int test;cin >> test;while(test--)
   solve();
}