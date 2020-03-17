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

int h, w, k;
vec<pi> cell;
void in(){
    cin >> h >> w >> k;
    rep(i,0,k){
        int r, c;
        cin >> r >> c;
        cell.push_back(pi(r, c));
    }
}

void solve(){
    
    vi hei(h, w);
    rep(i,0,k){
        int t = cell[i].first - 1;
        hei[t]--;
    }

    int heisum = sum(hei);
    int ansh = 0;
    int cumsum = 0;
    rep(i,0,h){
        cumsum += hei[i];
        if(cumsum > heisum / 2){
            ansh = i;
            break;
        }
    }

    vi wid(w, h);
    rep(i,0,k){
        int t = cell[i].second - 1;
        wid[t]--;
    }

    int widsum = sum(wid);
    int answ = 0;
    cumsum = 0;
    rep(i,0,w){
        cumsum += wid[i];
        if(cumsum > widsum / 2){
            answ = i;
            break;
        }
    }


    int heicost = ansh * (ansh + 1) / 2 * w;
    heicost += (h - ansh - 1) * (h - ansh) / 2 * w;
    int widcost = answ * (answ + 1) / 2 * h; 
    widcost += (w - answ - 1) * (w - answ) / 2 * h;

    int ans = heicost + widcost;

    for(auto e : cell){
        ans -= abs(ansh + 1 - e.first) + abs(answ + 1 - e.second);
    }

    print(ans);
    

    



}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
