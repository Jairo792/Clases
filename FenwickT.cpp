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
const int MAXN = 200000;
vector<ll> ft(MAXN + 1);

int ult(int i){
    return i &(-i);
}

ll query(int i){
    ll sum = 0;
    for(; i > 0 ; i -= ult(i)){
        sum += ft[i];
    }
    
    return sum;
}

void update(int i, ll k){
    for(i++; i <= MAXN; i += ult(i)){
        ft[i] += k;
    }
}


void solve(){
    int n,q;
    cin >> n >> q;
    vector<ll> after(n);

    forn(i,n){
        cin >> after[i];
        update(i,after[i]);
    }

    forn(i,q){
        int a;
        cin >> a;
        if(a == 1){
            int b;
            ll c;
            cin >> b >> c;
            ll d = c - after[b-1];
            after[b-1] = c;
            update(b-1,d);
        }else {
            int l,r;
            cin >> l >> r;
            cout << query(r) - query(l-1) << '\n';
        }
    }
}

int main (){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt = 1; 
    if(cases)
     cin >> tt; 
    forn(TT,tt){solve();}
}



