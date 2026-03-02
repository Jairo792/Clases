#include <bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) fore(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define mp        make_pair
#define pb        push_back
#define fst first
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define snd second
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}
template<class T,class U>ostream&operator<<(ostream&o,pair<T,U>const&p){return o<<"("<<p.fst<<", "<<p.snd<<")";}
template<class T>void maxa(T&x,T const&y){  x=max(x,y);  }
template<class T>void mina(T&x,T const&y){  x=min(x,y);  }
template<class T>void sort2(T&x,T&y){  if(y<x)swap(x,y);  }
template<class T>void sort3(T&x,T&y,T&z){  sort2(x,y);sort2(y,z);sort2(x,y);  }
#define RAYA cerr<<"===============================================\n"
const int cases = 0;

void solve(){
int n;
cin >> n;
    vector<ll>casos(n + 5);
    ll sum = 0;
    casos[0]++;
    forn(i,n){
        ll x;
        cin >> x;
        sum += x;
        casos[(sum % n + n) % n]++;
    }
    
    
   // cout << casos << '\n';
    ll total = 0;

    for(int i = 0; i < n+5; i++){
        ll suma  = casos[i] * (casos[i] - 1LL) / 2LL;
        total += suma;
    }
    cout << total << '\n';
}

int main (){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt = 1; 
    if(cases)
     cin >> tt; 
    forn(TT,tt){solve();}
}



