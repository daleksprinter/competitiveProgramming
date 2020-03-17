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


/* main */

int n, q;
string s;
vec<pi> query;
void in(){
    cin >> n >> q;
    cin >> s;
    rep(i,0,q){
        char a, b;
        cin >> a >> b;
        query.push_back(pi(a, b));
    }
}


bool dieright(int pos){

    char t = s[pos];
    int ind = pos;

    rep(i,0,q){
        char c = query[i].first;
        char op = query[i].second;
        if(t == c){
            if(op == 'R'){
                ind++;
            }else{
                ind--;
            }
            
            if(ind == n) return true;
            if(ind == -1) return false;

            t = s[ind];
        }
    }

    return false;

}

bool dieleft(int pos){
    char t = s[pos];
    int ind = pos;
    rep(i,0,q){
        char c = query[i].first;
        char op = query[i].second;
        if(t == c){
            if(op == 'L'){
                ind--;
            }else{
                ind++;
            }
            if(ind == -1) return true;
            if(ind == n) return false;
            t = s[ind];
        }
    }
    return false;
}



void solve(){

    int left = -1;
    int right = n;

    rep(i,0,20){
        int mid = (left + right) / 2;
        if(dieright(mid)){
            right = mid;
        }else{
            left = mid;
        }
        if(left == n or right == -1) break;
    }

    int ansr = right;

    left = -1;
    right = n;
    rep(i,0,20){
        int mid = (left + right) / 2;
        if(dieleft(mid)){
            left = mid;
        }else{
            right = mid;
        }
        if(left == n or right == -1) break;
    }
    int ansl = left;

    int dead = (n - ansr) + ansl + 1;

    print(n - dead);

}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
