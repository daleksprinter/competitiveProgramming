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


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 100100100100100100;
const int mod = 1e9;
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




/* main */
struct quick_find{

    vector<vector<int> > g2i;
    vector<int> i2g;

    quick_find(int n){
        g2i.resize(n, vector<int>());
        i2g.resize(n);
        rep(i,0,n) {
            g2i[i].push_back(i);
            i2g[i] = i;
        }
    }

    void merge(int a, int b){
        if(root(a) == root(b)) return;

        if(g2i[root(a)].size() < g2i[root(b)].size()) swap(a, b);

        int ra = root(a), rb = root(b);

        for(int e : g2i[rb]) i2g[e] = ra;

        g2i[ra].insert(g2i[ra].end(), g2i[rb].begin(), g2i[rb].end());

        g2i[rb].clear();

    }


    bool issame(int a, int b){
        return i2g[a] == i2g[b];
    }

    int root(int a){
        return i2g[a];
    }

    int comp(){
        int ret = 0;
        for(int i = 0; i < g2i.size(); i++){
            if(g2i[i].size() > 0) ret++;
        }
        return ret;
    }


};


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    quick_find qf = quick_find(n);

    rep(i,0,m){
        int f, t; cin >> f >> t;
        f--; t--;
        qf.merge(f, t);
    }

    print(qf.comp()-1);


    
    



 
    
    


    

    
   
    













}






    










    




    









