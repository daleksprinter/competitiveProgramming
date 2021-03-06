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
//const int inf = pow(2, 31) - 10;
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

    vec<set<int>> hands(2);
    rep(i,0,n) hands[0].insert(input());
    rep(i,1,2 * n + 1) if(not exist(hands[0], i)) hands[1].insert(i);

    bool turn = 0;
    int field = 0;
    while(not hands[0].empty() && not hands[1].empty()){
        auto itr = hands[turn].lower_bound(field);
        if(itr == hands[turn].end()){
            field = 0;
        }else{
            field = *itr;
            hands[turn].erase(itr);
        }
        turn = (turn + 1) % 2;
    }

    cout << hands[1].size() << endl << hands[0].size() << endl;
    






    




    

    





    

   




    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









