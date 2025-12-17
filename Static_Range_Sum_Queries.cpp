#include <bits/stdc++.h>
typedef long long ll;
#define forn(i,n) for(int i = 0; i < n; i++)
using namespace std;
 
int main (){
  int n, m;
  cin >> n >> m;
  
  vector <ll> nums(n);
  vector <ll> tablita(n);
  
  forn(i,n){
    cin >> nums[i];
  }
  
  partial_sum(nums.begin(), nums.end(), tablita.begin());
  
  forn(i,m){
    int x,y;
    cin >> x >> y;
    if (x != 1)
     cout << tablita[y-1] - tablita[x-2] << '\n';
    else
     cout << tablita[y-1] << '\n';
  }
  
}
