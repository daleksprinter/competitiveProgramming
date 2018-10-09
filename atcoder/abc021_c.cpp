#include <bits/stdc++.h>
using namespace std;


/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))
#define Sort(v) sort(all(v))


/* constant */
const int inf = 100100100100100100;
const int mod = 1000000007;
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
vector<int> cs(vector<int> arr){
    vector<int> tmp;
    if(arr.size() == 0) return tmp;
    tmp.push_back(arr[0]);
    rep(i,1,arr.size()){
        tmp.push_back(tmp.back() + arr[i]);
    }
    return tmp;
}

/* math_library */
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b){ return a * b / gcd(a,b);}



/* main */




signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = input();

    int f, t; cin >> f >> t;
    f--; t--;

    int m = input();

    vector< vector<int> > edges(n);

    rep(i,0,m){
        int frm, to; cin >> frm >> to;
        frm--; to--;
        edges[frm].push_back(to);
        edges[to].push_back(frm);
    }

    vector<int> dist(n, inf);
    dist[f] = 1;
    vector<int> comb(n, 0);
    comb[f] = 1;
 

    queue< pair<int, int> > q;

    q.push(make_pair(f,1));

    while(not q.empty()){

        pair<int, int> t = q.front();
        q.pop();


        rep(i,0,edges[t.first].size()){
            int nxt = edges[t.first][i];
            if(dist[nxt] >= t.second + 1) {
                comb[nxt] += comb[t.first];
                comb[nxt] %= mod;
            }
            if(dist[nxt] == inf) {
                dist[nxt] = t.second + 1;
                q.push(make_pair(nxt, t.second + 1));
            }
            

        }

    }

    print(comb[t] % mod);
   
    

    

    








}   
