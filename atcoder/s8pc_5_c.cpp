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

/* main */

int q;
void in(){
    cin >> q;
}

void solve(){
    
    rep(i,0,q){
        string s = raw_input();
        string a = "";
        string b = "";
        int n = sz(s);
        int ta = 0, tb = 0;
        for(char e : s){
            if(e == '('){
                ta++;
            }
        }
        if(ta != n / 2){
            print("No");
            continue;
        }

       
        int cnta = 0, cntb = 0;
        rep(j,0,n){
            if(s[j] == '('){
                if(cnta < n / 4){
                    a += s[j];
                    cnta++;
                }else{
                    b += s[j];
                }
            }else{
                if(cntb < n / 4){
                    b += s[j];
                    cntb++;
                }else{
                    a += s[j];
                }
            }
        }

        rep(j,0,n / 2) b[j] = (b[j] == '(' ? ')' : '(');
        
        bool isok = true;
        int d = 0;
        rep(j,0,n / 2){
            d += (a[j] == '(' ? 1 : -1);
            if(d < 0) isok = false;
        }

        if(d > 0)isok = false;

        d = 0;
        rep(j,0,n/2){
            d += (b[j] == '(' ? 1 : -1);
            if(d < 0)isok = false;
        }
        if(d > 0)isok = false;

        cout << (isok ? "Yes" : "No") << endl;
        
    }


}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
