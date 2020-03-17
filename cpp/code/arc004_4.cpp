#include "bits/stdc++.h"
using namespace std;


/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))
#define isin(tx, ty, w, h) (0 <= tx && tx <= w && 0 <= ty && ty <= h)


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = pow(2, 62);
const int mod = 1e9 + 7;
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};

/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
template<class T> void printx(T n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";each(s, e){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";each(mp, e){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}




/* main */


map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}


vi pfactor(int n){
    vi ret;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            ret.push_back(i);
            n /= i;
        }
    }
    if(n != 1) ret.push_back(n);
    return ret;
}

struct binomial_coefficient{
    vector<int> facts;
    vector<int> invs;

    int mod_pow(int x, int n, int m){if(n== 0) return 1;int res = mod_pow(x*x%m,n/2,m);if(n&1) res = res*x%m;return res;}
    int inv(int n){return mod_pow(n,mod-2,mod);}

    binomial_coefficient(int n){
        facts.push_back(1); invs.push_back(1);
        for(int i = 1; i <= n; i++){
            facts.push_back(facts[i-1]*i%mod);
            invs.push_back(inv(facts[i]));
        }
        
    }

    int nPr(int n, int r){
        if(r > n) return 0;
        return (facts[n]%mod * invs[n-r]% mod)%mod;
    }

    int nCr(int n, int r){
        if(r > n) return 0;
        return facts[n]%mod * invs[n-r]%mod * invs[r] % mod;
    }

    int nHr(int n, int r){
        if(n==0 && r==0) return 1;
        return nCr(n+r-1, r);
    }

};

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    bool isnega = n < 0;

    n = abs(n);

    auto mp = prime_factor(n);

    binomial_coefficient bf(200000);

    int nat = 1;

    each(mp, itr){
        nat *= bf.nHr(m, itr -> second);
        nat %= mod;

    }

    int ans = 0;

    if(not isnega){
        ans += nat;
        for(int i = 2; i <= m; i += 2){
            ans += nat * bf.nCr(m, i);
            ans %= mod;
        }
    }else{
        for(int i = 1; i <= m; i += 2){
            ans += nat * bf.nCr(m, i);
            ans %= mod;
        }
    }

    print(ans % mod);


    





    

    


    




    





}






    

