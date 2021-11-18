#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mod 1000000007
typedef long long int ll;
using namespace std;

set<string> gen;

string reverse(string s, int l, int r){
   reverse(s.begin()+l, s.begin()+r+1);
   return s;
}

void solve(string s, int remLength){
   // Base case
   if(remLength == 0){
      gen.insert(s);
      return;
   }

   for (int i = 0; i < (int)s.length(); i++){
      for(int j = i; j < (int)s.length(); j++){
         string str  = s;
         str = reverse(s, i, j);
         solve(str, remLength-1);
      }
   }

}

signed main(){
   ios :: sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int test;cin >> test;while(test--){
      string s, t;
      cin >> s >> t;

      set<string> gen1;
      set<string> gen2;

      solve(s, 2);
      gen1 = gen;
      gen.clear();

      solve(t, 2);
      gen2 = gen;
      gen.clear();

      int flag = 0;
      for(auto i: gen1){
         if(gen2.find(i) != gen2.end()){
            cout << "YES\n";
            flag = 1;
            break;
         }
      }

      if(!flag){
         cout << "NO\n";
      }
   }
   return 0;
}