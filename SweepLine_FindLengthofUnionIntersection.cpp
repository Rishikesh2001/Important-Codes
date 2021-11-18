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
   int n; cin >> n;

   vector<pair<int, int> > events;
   int min_r = 1e9, max_l = 0;
   for (int i = 0; i < n; i++){
      int l, r; 
      cin >> l >> r;
      min_r = min(min_r, r); max_l = max(max_l, l);
      events.pb({l, 1});
      events.pb({r, -1});
   }
   
   sortall(events);
   int count = 0, intersect= 0, union_len = 0;

   for(int i = 0; i < 2*n; i++){
      count += events[i].second;
      if(i!(2*n-1) && count > 0){
         union_len += (events[i+1].first - events[i].first);
      }
   }

   // Length of intersection will be min(r) - max(l) 
   intersect = max(min_r - max_l, 0);

   cout << union_len << " " << intersect << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}