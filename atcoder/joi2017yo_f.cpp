#include "bits/stdc++.h"
using namespace std;

/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
//#define int long long
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
const int inf = 1 << 30;
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
int n, m, d;
vi temp;
vec<vec<pi>> edges(10101);
void in(){

    cin >> n >> m >> d;
    rep(i,0,n) temp.push_back(input());

    rep(i,0,m){
        int f, t, c;
        cin >> f >> t >> c;
        f--; t--;
        edges[f].push_back(pi(t, c));
        edges[t].push_back(pi(f, c));
    }

}

void solve(){

    int dist[n][d + 1];
    rep(i,0,n)rep(k,0,d + 1) dist[i][k] = inf;
    dist[0][d] = 0;

    priority_queue<vi, vec<vi>, greater<vi>> que;
    //dist, vertice, templature, rest
    que.push({0, 0, 0, d});
    dist[0][d] = 0;

    while(not que.empty()){
        
        int len = que.top()[0];
        int v = que.top()[1];
        int templa = que.top()[2];
        int rest = que.top()[3];

        que.pop();


        if(v == n - 1){
            print(len);
            exit(0);
        }

        rep(i,0,sz(edges[v])){
            int nxt = edges[v][i].first;
            int ton = edges[v][i].second;
            
            int t = max(0, rest - ton);
            if(t == 0){
                if(templa == 0 && temp[nxt] == 2){ // cold to hot
                    if(chmin(dist[nxt][d], len + ton)){
                        que.push({dist[nxt][d], nxt, 2, d});
                    }
                }

                if(templa == 2 && temp[nxt] == 0){ // hot to cold
                    if(chmin(dist[nxt][d], len + ton)){
                        que.push({dist[nxt][d], nxt, 0, d});
                    }
                }
            }


            if(templa == 0 && temp[nxt] == 2) continue;
            if(templa == 2 && temp[nxt] == 0) continue;
            t = (templa == temp[nxt] ? d : t);
            if(chmin(dist[nxt][t], len + ton)){
                que.push({dist[nxt][t], nxt, templa, t});
            }
        



        }


    }


    int ans = inf;
    rep(i,0,d + 1){
        chmin(ans, dist[n - 1][i]);
    }
    print(ans);




}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    in();
    solve();
    
}
