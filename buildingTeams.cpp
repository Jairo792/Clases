#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define fore(e,c) for(const auto &e : (c))
 
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"[ ";
    for(auto y : v) out<<y<<" ";
    out<<" ]";
    return out;
}
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int N = 200001;
bool band = 0;
vector <int> visited(N,-1);
 
void BFS (int x, vector<vector<int>>&adj){
    visited[x] = 1;
    queue<int>q;
    q.push(x);
    
    while (!q.empty()){
        x = q.front();
        q.pop();
        
        for (auto u : adj[x]){
            if (visited[u] != -1) {
                if (visited[u] == visited[x])
                   band = 1;
                else
                   continue; 
            } else {
                if (visited[x] == 1)
                    visited[u] = 2;
                else
                    visited[u] = 1;
                q.push(u);
            }
        }
             
    }
}
 
 
int main (){
  int n, m;
  cin >> n >> m;
  vector <vector <int>> adj(n + 1);
  
  forn(i,m){
      int l,r;
      cin >> l >> r;
      adj[l].push_back(r);
      adj[r].push_back(l); 
  }
  
  forr(i,1,n+1){
     if (visited[i] == -1)
        BFS(i,adj);
     if (band) {
        cout << "IMPOSSIBLE\n";
        return 0;
     }
  }
  
  forr(i,1,n+1){
      cout << visited[i] << ' ';
  }
  
}
