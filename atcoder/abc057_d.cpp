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
const string alpha = "abcdefghijklmnopqrstuvwxyz";

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

    int comb[51][51]; 
    rep(i,0,51){
        for(int j = 0; j <= i; j++){
            if(j == 0 or j== i){
                comb[i][j] = 1;
            }else{
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j]; 
            }
        }
    }


    int n, a, b; cin >> n >> a >> b;
    vi arr; 

    map<int, int> mp;
    rep(i,0,n){
        int t = input();
        arr.push_back(t);
        mp[t]++;
    }

    sort(all(arr));
    reverse(all(arr));

    map<int, int> use;
    rep(i,0,a){ 
        use[arr[i]]++;
    }




   
    double mxavg = (double)accumulate(arr.begin(), arr.begin() + a, 0LL) / a;


    printf("%08f\n", mxavg);


    int lst = arr[a - 1];
    int ans = 0;


    int detuse = use[lst];
    rep(i,a,b + 1){
        if(detuse > mp[lst]) break;
        

        ans += comb[mp[lst]][detuse];
        detuse++;

        if(*arr.begin() != lst) break;

    }

    printf("%lld\n", ans);


    




    
    
    

    



    






    



    





    


    

}


