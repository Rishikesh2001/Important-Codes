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

vector<int> generate(vector<int> v){
   vector<int> vec;
   int m  = v.size();
   for(int i = 0; i < (1<<m); i++){
      int sum = 0;
      for(int j = 0; j < m; j++){
         if((1 << j) & i){
            sum += v[j];
         }
      }
      vec.pb(sum);
   }
   return vec;
}

void solve(){
   int n, target;
   cin >> n >> target;

   vector<int> vleft;
   vector<int> vright;

   for (int  i = 0; i < n/2; i++) {
      int x; cin >> x;
      vleft.pb(x);
   }

   for (int i = n/2; i < n; i++){
      int x; cin >> x;
      vright.pb(x);
   }

   vector<int> left = generate(vleft);
   vector<int> right = generate(vright);

   sort(left.begin(),left.end());
   sort(right.begin(), right.end());

   ll ans = 0;
   int ptr = (int)right.size() - 1;
   for(int u: left){
      if(u > target) break;
      while(ptr >= 0 && (u + right[ptr] > target)){
         ptr--;
      }
      ans += (ptr + 1);
   }

   cout << ans << "\n";
}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int test;cin >> test;while(test--)
   solve();
}