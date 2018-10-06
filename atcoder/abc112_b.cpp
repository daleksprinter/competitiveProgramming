#include <bits/stdc++.h>
using namespace std;

//macro-----------------------------------------------------------------------------------------
#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long

const int inf = 100100100100100;
const int mod = 1000000007;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};


//io_method
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
template<class T> void print(const T& n){cout << n << endl;}
void print(vector<int> arr){cout << arr[0];rep(i,1,arr.size()) cout << " " << arr[i];cout << endl;}
void print(pair<int, int> p){cout << p.first << " " << p.second;}
void print(vector<vector<int>> arr){rep(i,0,arr.size()){print(arr[i]);}}
void print(set<int> s){for(auto e = s.begin(); e != s.end(); e++){cout << *e << " ";}cout << endl;}
void print(map<int, int> mp){cout << "{";for(auto e = mp.begin(); e != mp.end(); e++){cout << "(" << e -> first << " " << e -> second << ")";}cout << "}" << endl;}

//main------------------------------------------------------------------------------------------

signed main(){


    int n = input();

    int t = input();

    vector<pair<int, int> > arr;
    rep(i,0,n){
        int c, x;
        cin >> c >> x;
        arr.push_back(make_pair(c,x));
    }

    sort(arr.begin(), arr.end());

    int m = inf;
    rep(i,0,n){
        if(arr[i].second <= t){
            m = min(m, arr[i].first);
        }
    }
    
    if(m == inf){
        print("TLE");
    }else{
        print(m);
    }









}   
