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
template<class T> void printans(vector<T> v){
    rep(i,0,v.size() - 1){
        cout << v[i] + 1 << " ";
    }
    cout << v[v.size() - 1] + 1 << endl;
}

/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename T>
auto cut(T &a, int l, int r){
    return T(a.begin()+l, a.begin()+r);   
}


/* main */
struct cumsum1d{
    int n;
    vector<int> arr;

    cumsum1d(int len){
        n = len;
        rep(i,0,n) arr.push_back(0);
    }

    void init(vector<int> vec){
        arr = vec;
        n = arr.size();
    }

    void add(int a, int b, int val = 1){
        arr[a] += val;
        if(b + 1 < n) arr[b + 1] -= val;
    }

    void build(){
        rep(i,1,n) arr[i] += arr[i-1];
    }

    int query(int from, int to){
        int ret = arr[to];
        if(from) ret -= arr[from - 1];
        return ret;
    }

};


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = input();
    cumsum1d cs = cumsum1d(2000);

    rep(i,0,n){
        int a, b; char c;
        cin >> a >> c >> b;
        int tmpa = a / 100 * 60 + a % 100;
        int tmpb = b / 100 * 60 + b % 100;

        tmpa = tmpa/5 * 5;
        tmpb = (tmpb % 5 == 0 ? tmpb : (tmpb/5 + 1) * 5);

        cs.add(tmpa, tmpb);
        //cout << tmpa << " " << tmpb << endl;
        
    }

    cs.build();

    int i = 0;
    while(i < 2000){
        if(cs.arr[i] > 0){
            cout << setfill('0') << setw(2) << right << i / 60 << setfill('0') << setw(2) << right << i % 60 << "-";
            while(cs.arr[i + 1] > 0) i++;

            cout << setfill('0') << setw(2) << right << i / 60 << setfill('0') << setw(2) << right << i % 60 << endl;;
            i++;
        }
        i++;
    }










    














    









    






    

}


