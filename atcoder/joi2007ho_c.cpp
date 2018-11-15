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




signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);


    int n = input();

    set<pi> s;

    vec<pi> arr;

    rep(i,0,n){
        int x, y; cin >> x >> y;
        s.insert(pi(x, y));
    }

    
    int ans = 0;
    each(s, i){
        each(s, j){
            int x1 = i -> first, y1 = i -> second, x2 = j -> first, y2 = j -> second;
            int tx = x2 - x1, ty = y2 - y1;

            int x3 = x2 - ty, y3 = y2 + tx, x4 = x1 - ty, y4 = y1 + tx;

            if(exist(s, pi(x3, y3)) && exist(s, pi(x4, y4))){
                chmax(ans, (tx + ty) * (tx + ty) - 2 * (tx * ty));
            }

            int x5 = x2 + ty, y5 = y2 - tx, x6 = x1 + ty, y6 = y1 - tx; 

            if(exist(s, pi(x5, y5)) && exist(s, pi(x6, y6))){
                chmax(ans, (tx + ty) * (tx + ty) - 2 * (tx * ty));
            }
            
        }
    }

    print(ans);




    




    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









