#include <bits/stdc++.h>
using namespace std;


/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
//#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))
#define Sort(v) sort(all(v))


/* constant */
//const int inf = 100100100100100100;
const int mod = 998244353;
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
vector<int> cs(vector<int> arr){vector<int> tmp;if(arr.size() == 0) return tmp;tmp.push_back(arr[0]);rep(i,1,arr.size()){tmp.push_back(tmp.back() + arr[i]);}return tmp;}

/* math_library */
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b){ return a * b / gcd(a,b);}
int ceil(int a, int b){ if(a % b == 0) return a/b; else return a/b + 1;}
int digitlen(int n){int t = n;int cnt = 0;while(t){cnt++;t /= 10;}return cnt;}
bool isprime(int n){if(n < 2) return false;if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;for(int i = 7; i * i < n + 1; i += 2){if(n % i == 0) return false;}return true;}
int mod_pow(int x, int n, int m){if(n== 0) return 1;int res = mod_pow(x*x%m,n/2,m);if(n&1) res = res*x%m;return res;}
int digitsum(int n){int ret = 0;while(n){ret += n % 10;n /= 10;}return ret;}



/* main */


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;


    set<pair<int, int> >  broken;

    rep(i,0,m){
        int f,t; cin >> f >> t;

        f--; t--;
        if(f > t) swap(f,t);
        broken.insert(make_pair(f,t));
    }


    set<int> notvisited;
    rep(i,1,n) notvisited.insert(i);

    stack<int> stk;

    stk.push(0);

    vector<pair<int, int>> ans;


    while(not stk.empty()){

        int v = stk.top();
        stk.pop();

        vector<int> ers;
        each(notvisited, i){

            pair<int, int> p(v, *i);
            if(v > *i) p = make_pair(*i, v);

            if(not exist(broken, p)){
                ans.push_back(p);
                ers.push_back(*i);
                stk.push(*i);
            }
        }

        for(int e : ers){
            notvisited.erase(e);
        }

        

    }

    if(notvisited.size() > 0){
        print("No");
        return 0;
    }

    print("Yes");
    rep(i,0,ans.size()){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }


}






    










    




    









