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

int n, m, x;
int sx, sy, gx, gy;
vec<pi> ino;
char arr[1010][1010];
void in(){
    cin >> n >> m >> x;
    rep(i,0,n){
        rep(j,0,m){
            char t;
            cin >> t;
            arr[i][j] = t;
            if(t == 'S') sx = j, sy = i;
            if(t == 'G') gx = j, gy = i;
            if(t == '@') ino.push_back(pi(j, i));
        }
    }
}

void solve(){

    int dist[n][m];
    rep(i,0,n) rep(j,0,m) dist[i][j] = inf;

    queue<pi> que;
    rep(i,0,sz(ino)){
        int x = ino[i].first, y = ino[i].second;
        dist[y][x] = 0;
        que.push(ino[i]);
    }

    while(not que.empty()){

        int x = que.front().first, y = que.front().second;
        que.pop();

        rep(i,0,4){
            int tx = x + dx[i], ty = y + dy[i];

            if(isin(tx,0,m - 1) && isin(ty,0,n-1) && arr[ty][tx] != '#'){
                if(dist[ty][tx] > dist[y][x] + 1){
                    dist[ty][tx] = dist[y][x] + 1;
                    que.push(pi(tx, ty));
                }
            }
        }
    }
    bool field[n][m];

    
    rep(i,0,n){
        rep(j,0,m){
            if(arr[i][j] == '#' or dist[i][j] <= x) field[i][j] = false;
            else field[i][j] = true;
        }
    }
    
    if(not field[gy][gx]){
        print(-1);
        return ;
    }


    int ans[n][m];
    rep(i,0,n) rep(j,0,m) ans[i][j] = inf;
    ans[sy][sx] = 0;

    queue<pi> q;
    q.push(pi(sx, sy));


    while(not q.empty()){

        int x = q.front().first, y = q.front().second;
        q.pop();

        rep(i,0,4){
            int tx = x + dx[i], ty = y + dy[i];

            if(not field[ty][tx]) continue;

            if(ans[ty][tx] > ans[y][x] + 1){
                ans[ty][tx] = ans[y][x] + 1;
                q.push(pi(tx, ty));
            }
        }
    }

    /*
    rep(i,0,n){
        rep(j,0,m){
            cout << (ans[i][j] == inf ? -1 : ans[i][j]) << " ";
        }
        cout << endl;
    }
    */



    print((ans[gy][gx] == inf ? -1 : ans[gy][gx]));


    



}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
