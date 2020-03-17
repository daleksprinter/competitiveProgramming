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
const int inf = pow(2, 62);
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

vector<int> factors(int n){
    vector<int> facts;
    int i = 1;
    while(i*i < n){
        if(n % i == 0){
            facts.push_back(i);
            facts.push_back(n/i);
        }
        i++;
    }
    int sq = (int)sqrt(n);
    if(sq * sq == n) facts.push_back(sq);
    sort(all(facts));
    return facts;
    
}

vi primefact(int n){

    vi ret;
    int t = n;

    rep(i,2,sqrt(t + 10)){
        if(n % i == 0){
            while(n % i == 0){
                ret.push_back(i);
                n /= i;
            }
        }
    }
    if(n > 1) ret.push_back(n);
    sort(all(ret));

    return ret;

}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    

    int n = input();

    map<int, int> primes;

    rep(i,2,n + 1){
        vi pf = primefact(i);
        for(int e : pf) primes[e]++;
    }

    vi arr;

    each(primes, itr){
        arr.push_back(itr -> second);
    }


    sort(all(arr));
    reverse(all(arr));
    int ans = 0;


    int l = arr.size();

    rep(i,0,l) if(arr[i] >= 74) ans++;



    rep(i,0,l){
        if(arr[i] >= 14){
            rep(j,0,l){
                if(i != j && arr[j] >= 4) ans++;
            }
        }
    }

    rep(i,0,l){
        if(arr[i] >= 24){
            rep(j,0,l){
                if(i != j && arr[j] >= 2) ans++;
            }
        }
    }
    int t = 0;
    rep(i,0,l){
        if(arr[i] >= 4){
            rep(j,0,l){
                if(i != j && arr[j] >= 4){
                    rep(k,0,l){
                        if(k != i && k != j && arr[k] >= 2){
                            t++;
                        }
                    }
                }
            }
        }
    }



    print(ans + t/ 2);







    




    







    




   

    
    



    




    




    











    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









