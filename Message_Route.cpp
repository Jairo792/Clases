#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define fore(e,c) for(const auto &e : (c))
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int N = 100001;
vector <int> visited(N, -1);
vector <int> padres(N, 1);
 
void BFS (int n, vector<vector<int>>&adj){
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()){
        int x = q.front(); 
        q.pop();
        
        for (auto u: adj[x]){
            if (visited[u] != -1) continue;
            padres[u] = x;
            visited[u] = visited[x] + 1;
            q.push(u);
        }
    }
}
 
int main (){
  int n,m;
  cin >> n >> m;
  
  vector <vector <int>> adj(n + 1);
  
  for (int i = 0 ; i < m ; i++){
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  
  BFS (n,adj);
 
  if (visited[n] == -1) {
      cout << "IMPOSSIBLE\n";
  } else {
      cout << visited[n]<< '\n';
      vector <int> ans;
      int pos = n;
      ans.push_back(n);
      
      while (pos != 1){
          ans.push_back(padres[pos]);
          pos = padres[pos];
 
      }
      reverse(ans.begin(), ans.end());
      
      for(auto it: ans){
          cout << it << ' ';
      }
  }
  
} 
