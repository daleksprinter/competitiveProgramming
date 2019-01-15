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
#define pb push_back


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 1000100010010010;
const int mod = 1e9 + 7;
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
template<class T>auto cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}

/* main */
vec<vi> edges(100010);



signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    rep(i,0,m){
        int f, t; cin >> f >> t;
        f--; t--;
        edges[f].push_back(t);
        edges[t].push_back(f);
    }

    int l = 0;
    int r = edges[0][0];

    set<int> path; 
    path.insert(l); 
    path.insert(r);

    deque<int> ans;
    ans.push_front(l);
    ans.push_back(r);

    bool left = false;
    while(not left){
        bool tmp = true;
        for(int v : edges[l]){
            if(not exist(path, v)){
                tmp = false;
                l = v;
                path.insert(v);
                ans.push_front(v);
                break;
            }
        }
        left = tmp;
    }

    bool right = false;
    while(not right){
        bool tmp = true;
        for(int v : edges[r]){
            if(not exist(path, v)){
                tmp = false;
                r = v;
                path.insert(v);
                ans.push_back(v);
                break;
            }
        }
        right = tmp;
    }
    print(ans.size());
    while(not ans.empty()){
        cout << ans.front() + 1;
        ans.pop_front();
        if(not ans.empty()) cout << " ";
    }
    cout << endl;








    

    

    


    

}


