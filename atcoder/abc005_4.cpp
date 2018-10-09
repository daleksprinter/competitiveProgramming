#include <bits/stdc++.h>
using namespace std;


/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))
#define Sort(v) sort(all(v))


/* constant */
const int inf = 100100100100100100;
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
vector<int> cs(vector<int> arr){
    vector<int> tmp;
    if(arr.size() == 0) return tmp;
    tmp.push_back(arr[0]);
    rep(i,1,arr.size()){
        tmp.push_back(tmp.back() + arr[i]);
    }
    return tmp;
}

/* math_library */
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b){ return a * b / gcd(a,b);}


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
    return facts;
}

/* main */

int n;
vector<vector<int> > takoyaki;

int cumsum(int x1, int y1, int c, int d){
    int x2 = min(c, n-1), y2 = min(d, n-1);

    return takoyaki[y2][x2] - (x1 - 1 > -1 ? takoyaki[y2][x1-1] : 0) - (y1 - 1 > -1 ? takoyaki[y1-1][x2] : 0) + (y1 -1 > -1 && x1 -1 > -1 ? takoyaki[y1-1][x1-1] : 0);

}


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    n = input();

    rep(i,0,n){
        vector<int> tmp; rep(j,0,n) tmp.push_back(input());
        takoyaki.push_back(cs(tmp));
    }

    rep(i,1,n){
        rep(j,0,n){
            takoyaki[i][j] = takoyaki[i-1][j] + takoyaki[i][j];
        }
    }

    int m = input();

    vector<int> takoarea(n * n + 10, 0);
    
    rep(i,0,n){
        rep(j,0,n){
            rep(k,1,n+1){
                rep(l,1,n+1){
                    chmax(takoarea[k * l], cumsum(i,j, i + k - 1, j + l -1));
                }
            }
        }
    }
    
    rep(i,1,takoarea.size()){
        chmax(takoarea[i], takoarea[i-1]);
    }



    rep(i,0,m){

        print(takoarea[input()]);
    }

    

    

    

   




    
   
    

    

    








}   
