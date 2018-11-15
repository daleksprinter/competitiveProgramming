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
int digitlen(int n){
    int cnt = 0;
    while(n){
        cnt++;
        n /= 10;
    }
    return cnt;
}



signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    std::ostringstream sout;


    int n, m; cin >> n >> m;

    vector<vec<pi>> arr(n + 5);

    rep(i,0,m){
        int p, y; cin >> p >> y;
        arr[p].push_back(make_pair(y, i));
    }

    rep(i,0,n + 5){
        if(not arr[i].empty()) sort(all(arr[i]));
    }

    vec<pi> ans(m + 5, pi(0,0));

    rep(i,0,arr.size()){
        if(not arr[i].empty()){
            rep(j,0,arr[i].size()){
                pi tmp = arr[i][j];
                ans[tmp.second] = make_pair(i, j + 1);
            }
        }
    }
    
    for(auto e : ans){
        if(e != pi(0, 0)){
            printf("%06lld%06lld\n", e.first, e.second);
        }
    }

    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









