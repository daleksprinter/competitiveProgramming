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
int n;
string s;

string solve(char fir, char sec){

    string ret = ""; ret += fir; ret += sec;

    rep(i,1,n + 10){
        if(s[i % n] == 'o'){
            if(ret[i] == 'S') ret += ret[i-1];
            else ret += (ret[i-1] == 'S' ? 'W' : 'S');
        }else{
            if(ret[i] == 'S') ret += (ret[i-1] == 'S' ? 'W' : 'S');
            else ret += ret[i-1];
        }
    }

    bool isok = true;

    rep(i,0,5){
        if(ret[i] != ret[n + i]){
            isok = false;
            break;
        }
    }

    if(isok) return ret.substr(0, n);
    else return "-1";
}





signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    n = input();
    s = raw_input();

    string tmp;
    if((tmp = solve('S', 'S')) != "-1") {
        print(tmp);
        return 0;
    }
    if((tmp = solve('S', 'W')) != "-1"){
        print(tmp);
        return 0;
    }
    if((tmp = solve('W', 'S')) != "-1"){
        print(tmp);
        return 0;
    }
    if((tmp = solve('W', 'W')) != "-1"){
        print(tmp);
        return 0;
    }

    print(-1);

    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









