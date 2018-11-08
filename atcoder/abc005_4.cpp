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

struct cumsum2d{
    int x;
    int y;
    vector<vector<int>> arr;

    cumsum2d(int width, int height){
        x = width;
        y = height;
        arr = vector<vector<int>>(x, vector<int>(y, 0));
    }

    void init(vector<vector<int>> vec){
        arr = vec;
        x = arr[0].size();
        y = arr.size();
        
    }

    void add(int x1, int y1, int x2, int y2, int val = 1){
        arr[y1][x1] += val;
        if(x2 + 1 < x) arr[y1][x2 + 1] -= val;
        if(y2 + 1 < y) arr[y2 + 1][x1] -= val;
        if(x2 + 1 < x && y2 + 1 < y) arr[y2 + 1][x2 + 1] += val; 
    }

    void build(){
        for(int i = 0; i < y; i++){
            for(int j = 1; j < x; j++){
                arr[i][j] += arr[i][j - 1];
            }
        }
        for(int i = 1; i < y; i++){
            for(int j = 0; j < x; j++){
                arr[i][j] += arr[i - 1][j];
            }
        }
    }

    int query(int x1, int y1, int x2, int y2){
        int ret = arr[y2][x2];
        if(-1 < x1 - 1) ret -= arr[y2][x1 - 1];
        if(-1 < y1 - 1) ret -= arr[y1 - 1][x2];
        if(-1 < x1 - 1 && -1 < y1 - 1) ret += arr[y1 - 1][x1 - 1];
        return ret;
    }

};



signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = input();

    vec<vi> arr(n, vi(n,0));

    rep(i,0,n){
        rep(j,0,n){
            arr[i][j] = input();
        }
    }
    cumsum2d cs = cumsum2d(n, n);
    cs.init(arr);

    cs.build();




    int mx[n * n + 10]; memset(mx, 0, sizeof(mx));

    rep(i,0,n){
        rep(j,0,n){
            rep(k,i,n){
                rep(l,j,n){
                    chmax(mx[(k - i + 1) * (l - j + 1)], cs.query(i,j,k,l));
                }
            }
        }
    }

    rep(i,1,n * n + 10) chmax(mx[i], mx[i - 1]);

    int q = input();

    rep(i,0,q){
        int area = input();
        print(mx[area]);
    }






    


    
    

    
    






    




    

    





    

   




    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









