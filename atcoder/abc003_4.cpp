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
#define isin(a, b, c) (b <= a && a <= c)
#define println cout << "\n";
#define sz(v) (int)v.size()
#define bin(x) static_cast<bitset<16> >(x)


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef map<int, int> mi;
typedef set<int> si;


/* constant */
const int inf = 1LL << 62;
const int mod = 1e9 + 7;
const int dx[8]={1,0,-1,0,-1,1,-1,1};
const int dy[8]={0,1,0,-1,-1,-1,1,1};
const string alphabet = "abcdefghijklmnopqrstuvwxyz";

/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
template<class T> void printx(T n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T, class U, class V> void printx(tuple<T, U, V> t){cout << "{" << get<0>(t) << "," << get<1>(t) <<"," << get<2>(t) << "}" << endl;}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";each(s, e){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";each(mp, e){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}
template<class T> void printans(vec<T> v){rep(i,0,sz(v)){cout << v[i] << (i == sz(v) - 1 ? "" : " ");}cout << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}


/* math_method */
int ceil(int a, int b){return a / b + (a % b > 0);}


int popcount(long bits){
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
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
/* main */

int h, w;
int r, c;
int d, l;
void in(){
    cin >> h >> w >> r >> c >> d >> l;
}

void solve(){

    binomial_coefficient bf(101010);

    int ret = 0;
    rep(i,1,1 << 4){

        int y = r, x = c;
        rep(j,0,4) y -= (j % 2 == 0 && i & (1 << j)), x -= (j % 2 == 1 && i & (1 << j));
        if(y <= 0 or x <= 0) continue;
        int t = bf.nCr(y * x, d) * bf.nCr(y * x - d, l) % mod;
        ret += (popcount(i) % 2 == 0 ? -t : t);

        ret += mod; ret %= mod;
    }
    int ans = bf.nCr(r * c, d) * bf.nCr(r * c - d, l) % mod;
    ans -= ret;
    ans += mod; ans %= mod;
    cout << (h - r + 1) * (w - c + 1) % mod * ans % mod << endl;

}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
