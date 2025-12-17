#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"[ ";
    for(auto y : v) out<<y<<" ";
    out<<" ]";
    return out;
}

int main (){
  int n,m,k;
  cin >> n >> m >> k;
  
  vector <ll> temps(200005,0);
  vector <ll> resta(200005,0);
  vector <ll> suma(200005,0);
  
  forn(i,n){
      int l,r;
      cin >> l >> r;
      suma[l] += 1;
      resta[r] += 1;
  }
  
  ll cnt = 0;
  
  for(int i = 1; i < (int)temps.size(); i++){
      temps[i] = cnt + suma[i];
      cnt += suma[i];
      cnt -= resta[i];
  }
  
  forn(i,(int)temps.size()) {
      if(temps[i] >= m) {
          temps[i] = 1;
      } else
          temps[i] = 0;
  }
  
  partial_sum(temps.begin(), temps.end(), suma.begin());
  
  forn(i,k){
      int l,r;
      cin >> l >> r;
      cout << suma[r] - suma[l-1] << '\n';      
  } 
  
}
