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

int h, w;
bool arr[100][100];
//#...true, '.'...false
bool shrink[100][100];
bool ans[100][100];
void in(){
    cin >> h >> w;
    rep(i,0,h){
        rep(j,0,w){
            char t;
            cin >> t;
            arr[i][j] = (t == '#');
            shrink[i][j] = true;
            ans[i][j] = false;
        }
    }
}

void solve(){
    //収縮処理
    rep(i,0,h){
        rep(j,0,w){
            if(not arr[i][j]){
                shrink[i][j] = false;
                rep(k,0,8){
                    int tx = j + dx[k];
                    int ty = i + dy[k];
                    if(isin(tx, 0, w) && isin(ty,0,h)){
                        shrink[ty][tx] = false;
                    }
                }
            }
        }
    }

    //復元
    rep(i,0,h){
        rep(j,0,w){
            if(shrink[i][j]){
                ans[i][j] = true;
                rep(k,0,8){
                    int tx = j + dx[k];
                    int ty = i + dy[k];
                    if(isin(tx, 0, w) && isin(ty,0,h)){
                        ans[ty][tx] = true;
                    }
                }
            }
        }
    }


    bool isok = true;
    rep(i,0,h){
        rep(j,0,w){
            if(arr[i][j] != ans[i][j]){
                isok = false;
                j = inf, i = inf;
                break;
            }
        }
    }
    

    if(isok){
        print("possible");
        rep(i,0,h){
            rep(j,0,w){
                cout << (shrink[i][j] ? "#" : ".");
            }
            cout << endl;
        }
    }else{
        print("impossible");
    }
    


}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}

