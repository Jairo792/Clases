#include <bits/stdc++.h>
typedef long long ll;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
using namespace std;
 
bool search(vector<ll>&t, int l, int r, ll number){
    ll sum = t[l-1];
    ll l1 = l;
    
    while (r-l>1){
        int mid = (l + r) / 2;
         if ( t[mid] - sum >= number){
             r = mid;   
         } else
             l = mid;
    }
    
    if (t[r] - sum == number)
        return 1;
    return 0;
}
 
int main (){
   int n;
   ll m;
   cin >> n >> m;
   vector <ll> nums(n);
   vector <ll> tabla(n + 1, 0);
   
   forn(i,n){
        cin >> nums[i];
   } 
   
   partial_sum(nums.begin(), nums.end(), tabla.begin() + 1);
   
   int ans = 0;
   
   fore(i,1,n + 1){
      if (search(tabla,i,n,m) || nums[i-1] == m ) {
          ans++;
        
      }
   }
   
   cout << ans << '\n';
}
