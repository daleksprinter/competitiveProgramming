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

int factorial(int x){int res = 1;rep(i,2,x+1){res *= i;res %= mod;}return res;}
int mod_pow(int x, int n, int m){if(n== 0) return 1;int res = mod_pow(x*x%m,n/2,m);if(n&1) res = res*x%m;return res;}
int ncr(int n, int r){
    return factorial(n) / factorial(r) / factorial(n - r);
}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);




    int n = input();

    int ans = 0;

    rep(i,1,n + 1){
        rep(j,1,11){
            ans += ncr(10, j) % mod * mod_pow(i - 1, 10 - j, mod) % mod * mod_pow(n / i, 10,mod) % mod;
            ans %= mod;
        }
        ans %= mod;
    }

    print(ans);




    
    
    
    
    








    

    
    




    
    



    
    

    







   




    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









