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


    int n, k; cin >> n >> k;
    bool card = false;

    vi arr; 
    rep(i,0,k){
        int t = input();
        if(t) arr.push_back(t);
        else card = true;
    }
    if(card) k--;



    sort(all(arr));

    vec<pi> sets;

    int l = 0, r = 0;
    
    while(r < k){
        if(arr[r] == arr[l] + (r - l)){
            r++;
        }else{
            sets.push_back(pi(arr[l], arr[r - 1]));
            l = r;
        }
    }
    sets.push_back(pi(arr[l], arr[r - 1]));


    int ans = 0;
    if(not card){
        for(auto e : sets){
            chmax(ans, e.second - e.first + 1);
        }

    }else{
        rep(i,0,sets.size() - 1){
            if(sets[i].second == sets[i + 1].first - 2){
                chmax(ans, sets[i + 1].second - sets[i].first + 1);
            }else{
                chmax(ans, sets[i].second - sets[i].first + 1);
            }
        }
        chmax(ans, sets.back().second - sets.back().first + 1);
    }
    print(ans);


    




    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









