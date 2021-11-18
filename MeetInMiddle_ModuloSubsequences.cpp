#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define pb push_back
#define mp make_pair
#define mod 1000000007
typedef long long int ll;
using namespace std;

vector<int> generate(vector<int> v, int m){
   vector<int> vec;
   int size = (int)v.size();
   for (int i = 0; i < (1 << size); i++){
      int sum = 0;
      for (int j = 0; j < size; j++){
         if ((1 << j) & i){
            sum = (sum + v[j]%m);
         }
      }
      vec.pb(sum%m);
   }
   return vec;
}

void solve(){
   int n, m;
   cin >> n >> m;

   vector<int> vleft;
   vector<int> vright;

   for (int i = 0; i < n; i++){
      int x; cin >> x;
      if (i & 1)
         vleft.push_back(x);
      else
         vright.push_back(x);
   }

   vector<int> left = generate(vleft, m);
   vector<int> right = generate(vright, m);

   int ans = 0;
   sort(right.begin(), right.end());
   for(auto i: left){
      ans = max(ans, right[upper_bound(right.begin(), right.end(), m-1-i) - right.begin() - 1] + i);
   }

   cout << ans << "\n"; 
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   //int test;cin >> test;while(test--)
   solve();
}