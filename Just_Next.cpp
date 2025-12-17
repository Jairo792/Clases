#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)

using namespace std;

int main (){
  int tt;
  cin >> tt;
  
  while (tt--){
      int n;
      cin >> n;
      vector <int> numbers(n);
      
      forn(i,n){
        cin >> numbers[i];
      }
      
      if( next_permutation(numbers.begin(), numbers.end())){
      
        forn(i,n){
          cout << numbers[i];
        }
        cout << '\n';
      } else
        cout << -1 << '\n';
  }
}
