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

int n;
int a, b, c;
vi arr;
void in(){
    cin >> n;
    cin >> a >> b >> c;
    rep(i,0,n) arr.push_back(input());
}

struct cumsum1d{
    int n;
    vector<int> arr;

    cumsum1d(int len){
        n = len;
        rep(i,0,n) arr.push_back(0);
    }

    void init(vector<int> vec){
        arr = vec;
        n = arr.size();
    }

    void add(int a, int b, int val = 1){
        arr[a] += val;
        if(b + 1 < n) arr[b + 1] -= val;
    }

    void build(){
        rep(i,1,n) arr[i] += arr[i-1];
    }

    int query(int from, int to){
        int ret = arr[to];
        if(from) ret -= arr[from - 1];
        return ret;
    }

};


void solve(){

    
    int ans = inf;
    sort(all(arr));


    do{
        cumsum1d cs = cumsum1d(10);
        cs.init(arr);
        cs.build();

        rep(i,0, n - 2){
            rep(j,i + 1, n - 1){
                rep(k,j + 1, n){
                    int ta = cs.query(0, i);
                    int tb = cs.query(i + 1, j);
                    int tc = cs.query(j + 1, k);
                    int cnt = abs(a - ta) + abs(b - tb) + abs(c - tc);
                    cnt += (i) * 10;
                    cnt += (j - (i + 1)) * 10;
                    cnt += (k - (j + 1)) * 10;

                    chmin(ans, cnt);
                }
            }
        }
    }while(next_permutation(all(arr)));

    print(ans);

}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
