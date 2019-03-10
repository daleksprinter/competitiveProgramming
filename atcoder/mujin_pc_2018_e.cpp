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

//U, D, L, R, UL, UR, DL, DR
const int dx[8]={0,0,-1,1,-1,1,-1,1};
const int dy[8]={-1,1,0,0,-1,-1,1,1};

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

int n, m, k;
string op;
char arr[1000][1000];
int sx, sy, gx, gy;
void in(){
    cin >> n >> m >> k;
    op = raw_input();
    rep(i,0,n){
        rep(j,0,m){
            char t; cin >> t;
            arr[i][j] = t;
            if(t == 'S') sx = j, sy = i;
            if(t == 'G') gx = j, gy = i;
        }
    }
}
map<char, int> dir = {{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};
int cost[101010][4];
void solve(){
    
    rep(i,0,k) rep(j,0,4) cost[i][j] = inf;
    rep(i,0,k) cost[i][dir[op[i]]] = 0;
    rep(i,0,k){
        int j = (i - 1 + k) % k;
        int c = 1;
        int d = dir[op[i]];
        while(cost[j][d] == inf){
            cost[j][d] = c;
            c++;
            j = (j - 1 + k) % k;
        }
    }

    int dist[1010][1010];
    rep(i,0,1010) rep(j,0,1010) dist[i][j] = inf;
    priority_queue<pi, vec<pi>, greater<pi>> que;

    dist[sy][sx] = 0;
    que.push(pi(0, sy * 1010 + sx));

    while(not que.empty()){
        pi tmp = que.top(); que.pop();
        int d = tmp.first;
        int x = tmp.second % 1010;
        int y = tmp.second / 1010;

        if(dist[y][x] < d) continue;

        rep(i,0,4){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(not (isin(tx, 0, m - 1) && isin(ty, 0, n - 1))) continue;
            int movecost = d + cost[d % k][i] + 1;
            if(arr[ty][tx] != '#' && dist[ty][tx] > movecost){
                dist[ty][tx] = movecost;
                que.push(pi(dist[ty][tx], ty * 1010 + tx));
            }
        }
    }

    print(dist[gy][gx] == inf ? -1 : dist[gy][gx]);


}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}

