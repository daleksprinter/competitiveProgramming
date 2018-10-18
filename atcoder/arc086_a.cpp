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


/* alias */
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 100100100100100100;
const int mod = 1e9;
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



/* main */



signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);


    int n, k; cin >> n >> k;

    vi arr; rep(i,0,n) arr.push_back(input());

    map<int, int> mp;

    for(auto e : arr){
        mp[e]++;
    }

    vector<pi> tmp;
    each(mp, itr){
        tmp.push_back(make_pair(itr -> second, itr -> first));
    }

    

    sort(all(tmp));

    int ans = 0;

    if(tmp.size() <= k){
        print(ans);
        return 0;
    }
    
    rep(i,0,tmp.size() - k){
        ans += tmp[i].first;
    }

    print(ans);
    













}






    










    




    









