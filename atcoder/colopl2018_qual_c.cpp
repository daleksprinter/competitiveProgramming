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
#define pb push_back


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 1000100010010010;
const int mod = 1e9 + 7;
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};


/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
template<class T> void printx(T n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";each(s, e){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";each(mp, e){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> auto cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}

/* main */
int ceil(int a, int b){
    if( a % b == 0) return a / b;
    else return a / b + 1;
}



int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}



signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

    int l, r; cin >> l >> r;

    vi pow2; rep(i,l,r + 1) if(i % 2 == 0) pow2.pb(i);
    vi pow3; rep(i,l,r + 1) if(i % 3 == 0 && i % 2 != 0) pow3.pb(i);
    vi other; rep(i,l,r + 1) if(i % 2 != 0 && i % 3 != 0) other.pb(i);

    int ans = 0;




    rep(i,0,pow2.size() + 1){
        rep(j,0,pow3.size() + 1){
            rep(k,0,(1<<other.size())){
                vi use;
                if(i < pow2.size()) use.pb(pow2[i]);
                if(j < pow3.size()) use.pb(pow3[j]);
                rep(t,0,other.size()) 
                    if(k & (1 << t)) use.pb(other[t]);

                bool isok = true;
                rep(n,0,use.size()){
                    rep(m, n + 1, use.size()){
                        if(gcd(use[n], use[m]) > 1){
                            isok = false;
                            n = use.size();
                            m = use.size();
                        }
                    }
                }

                if(isok) ans++;

            }
        }
    }
    
    print(ans);




    



    


    

}


