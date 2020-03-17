#include "bits/stdc++.h"
using namespace std;


/* macro */
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))
#define sec second
#define fir first
#define pb push_back



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


struct Union_Find{
    vector<int> par;
    vector<int> rank;

    Union_Find(int n){
        for(int i = 0; i < n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int root(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = root(par[x]);
        }
    }

    void merge(int x, int y){
        x = root(x);
        y = root(y);

        if(x == y) return;

        if(rank[x] < rank[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

};

int rangesum(int a){
    return a * (a - 1) / 2;
}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;



    Union_Find uf = Union_Find(n);

    rep(i,0,m){
        int f, t; cin >> f >> t; f--; t--;
        uf.merge(f, t);
    }

    int c1 = 0, c2 = 0, c3 = 0;

    rep(i,0,n){
        int r = uf.root(i);
        int r0 = uf.root(0);
        int r1 = uf.root(1);

        if(r == r0) c1++;
        if(r == r1) c2++;
        if(r != r0 && r != r1) c3++;

    }



    print(rangesum(max(c1, c2) + c3) + rangesum(min(c1, c2)) - m);




}




