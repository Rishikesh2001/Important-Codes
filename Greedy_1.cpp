#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define mod 1000000007
typedef long long int ll;
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b){
   return a.second < b.second;
}

void solve(){
   int n; cin>>n;
   vector<pair<int, int> > v(n);
   for(int i = 0; i < n; i++){
      cin >> v[i].first;
      cin >> v[i].second;
   }
   sort(all(v), comp);

   int count=0;
   int prev = INT_MIN;
   for(int i =0; i < n; i++){
      if(prev <= v[i].first){
         count++;
         prev = v[i].second;
      }
   }

   cout << count << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}