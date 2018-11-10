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
const int mod = 1000000007;
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
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}

int ceil(int a, int b){
    if(a % b == 0) return a/b;
    else return a/b + 1;
}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;


    double ans = -1;
    int s = 0;
    int sugar = 0;

    rep(i,0,31){
        rep(j,0,31){
            int water = i * a + j * b;
            if(water * 100 <= f){
                rep(k,0,ceil(f - water * 100,c) + 1){
                    if(water * 100 + k * c <= f && water * e >= k * c){
                        int dnum = min((f - water * 100 - k * c) / d, (water * e - k * c)/ d);
                        int sugarsum = k * c + dnum * d;
                        if(water == 0) continue;
                        int beaker = water * 100 + sugarsum;
                        if(ans < (double)sugarsum / (double)beaker){

                            ans = (double)sugarsum / (double)beaker;
                            s = beaker;
                            sugar = sugarsum;
                        }
                    }
                }
            }
        }
    }
   
   
   
    cout << s << " " << sugar << endl;






   








    
    












    

    








    






    


    
    

    
    






    




    

    





    

   




    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









