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



signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = input();

    int arr[n][n];

    rep(i,0,n){
        rep(j,0,n){
            char t; cin >> t;

            if(t == '.') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }

    int hei = 0;
    int cnt = 0;
    while(hei < n){
        int wid = -1;
        rep(i,0,n) if(arr[hei][i] == 0) wid = i;

        if(wid > -1){
            if(hei < n - 1){
                rep(i,wid,n) arr[hei + 1][i] = 1;
            }
            cnt++;
        }
        hei++;
    }

    print(cnt);




    




    
    
    
    
    








    

    
    




    
    



    
    

    







   




    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









