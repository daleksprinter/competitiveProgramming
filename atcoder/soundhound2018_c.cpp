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

int h, w;
char arr[40][40];
struct edge{int to, cap, rev;};
vec<vec<edge>> edges(1700);
int pos(int y, int x){
    return y * w + x;
}
int source = 1600, sink = source + 1;
int ans = 0;
void in(){
    cin >> h >> w;
    rep(i,0,h){
        rep(j,0,w){
            cin >> arr[i][j];
            ans += arr[i][j] == '.';
        }
    }

    rep(i,0,h){
        rep(j,0,w){
            if(arr[i][j] == '*') continue;
            int f = pos(i,j);
            rep(k,0,4){
                int ty = i + dy[k];
                int tx = j + dx[k];
                if(!isin(ty,0,h-1) or !isin(tx,0,w-1) or arr[ty][tx] == '*') continue;
                if((i + j) % 2 == 1)  continue;
                int t = pos(ty, tx);
                edges[f].push_back((edge){t, 1, sz(edges[t])});
                edges[t].push_back((edge){f, 0, sz(edges[f]) - 1});
            } 
        }
    }

    rep(i,0,h){
        rep(j,0,w){
            if(arr[i][j] == '*') continue;
            if((i + j) % 2 == 0){
                int t = pos(i,j);
                edges[source].push_back((edge){t, 1, sz(edges[t])});
                edges[t].push_back((edge){source, 0, sz(edges[source]) - 1});
            }else{
                int f = pos(i,j);
                edges[f].push_back((edge){sink, 1, sz(edges[sink])});
                edges[sink].push_back((edge){f, 0, sz(edges[f]) - 1});
            }
        }
    }

}

bool visited[1700];
int dfs(int v, int t, int f){

    if(v == t) return f;
    visited[v] = true;

    rep(i,0,sz(edges[v])){
        edge e = edges[v][i];
        if(!visited[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                edges[v][i].cap -= d;
                edges[e.to][e.rev].cap += d;
                return d;
            }
        }
    } 

    return 0;
}

void solve(){

    int flow = 0;
    while(true){
        memset(visited, false, sizeof(visited));
        int f = dfs(source, sink, inf);
        if(f > 0) flow += f;
        else break;
    }

    print(ans - flow);


}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
