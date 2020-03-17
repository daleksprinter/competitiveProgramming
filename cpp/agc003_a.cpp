#include <bits/stdc++.h>
using namespace std;


/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())


/* constant */
const int inf = 100100100100100;
const int mod = 1000000007;
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};


/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
template<class T> void printx(T& n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T& n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";for(auto e = s.begin(); e != s.end(); e++){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";for(auto e = mp.begin(); e != mp.end(); e++){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



/* main */


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    

    string s = raw_input();

    map<char, int> mp;
    rep(i,0,s.size()){
        mp[s[i]]++;
    }
 
    
    if(exist(mp, 'N') && not exist(mp,'S') || exist(mp,'S') && not exist(mp, 'N') || exist(mp, 'W') && not exist(mp, 'E') || exist(mp, 'E') && not exist(mp, 'W')){
        print("No");
        return 0;
    }

    print("Yes");
    return 0;

    

    








}   
