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

int n, k;
vec<vi> arr(100000);

void in(){

    cin >> n >> k;
    rep(i,0,n){
        int t, d;
        cin >> t >> d;
        t--;
        arr[t].push_back(d);
    }

    rep(i,0,n){
        sort(all(arr[i]));
        reverse(all(arr[i]));
    }
}

void solve(){
    vi uni;
    vi oth;

    rep(i,0,n){
        rep(j,0,arr[i].size()){
            if(j == 0) uni.push_back(arr[i][j]);
            else oth.push_back(arr[i][j]);
        }
    }

    sort(all(uni));
    reverse(all(uni));
    sort(all(oth));
    reverse(all(oth));

    rep(i,1,uni.size()){
        uni[i] = uni[i - 1] + uni[i];
    }

    rep(i,1, oth.size()){
        oth[i] = oth[i - 1] + oth[i];
    }


    int ans = 0;
    rep(i,1,min(k + 1, (int)uni.size() + 1)){
        int tmp = 0;
        tmp += uni[i - 1];
        int rest = k - i;
        if(rest > 0 && oth.size() > 0){
            tmp += oth[min(rest - 1, (int)oth.size() - 1)];
        }
        chmax(ans, tmp + i * i);
    }

    print(ans);

    



}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
