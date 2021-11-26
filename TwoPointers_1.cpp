/*Given an array of N integers, find the number of subarrays with at most K distinct elements.*/
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

int n, k;
int a[100100];
int freq[1001000];

void solve(){
   cin >> n >> k;
   for(int i=0; i<n; i++){
      cin >> a[i];
   }

   int tail = 0, head = -1;
   int cntDistinct = 0;
   ll ans = 0;
   while(tail < n){
      while(head+1 < n && ((cntDistinct<=k && freq[a[head+1]]>0) || 
      (cntDistinct<k && freq[a[head+1]]==0))){
         head++;
         if(freq[a[head]] == 0){
            cntDistinct++;
         }
         freq[a[head]]++;
      }

      ans += (head-tail+1);

      if(head >= tail){
         if(freq[a[tail]] == 1){
            cntDistinct--;
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

/*
Input 
5
3 2
1 2 3
3 2
3 2 2
5 0
2 1 0 4 0
7 3
1 2 1 0 1 0 2
10 5
1 0 7 1 10 2 4 10 1 3

Output
5
6
0
28
46
*/
