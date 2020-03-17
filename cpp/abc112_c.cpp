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

    vector<vector<int> > arr;

    rep(i,0,n){
        int x,y,h; cin >> x >> y >> h;
        arr.push_back({x,y,h});
    }

    rep(i,0,101){
        rep(j,0,101){
            rep(h,-220, 220){
                int hei = arr[0][2] + h;
                if(hei < 1) continue;

                bool isfind = true;
                rep(k,0, n){
                    if(arr[k][2] == 0 && hei - abs(i - arr[k][0]) - abs(j - arr[k][1]) <= 0|| hei - abs(i - arr[k][0]) - abs(j - arr[k][1]) == arr[k][2]){
                        continue;
                    }else{
                        isfind = false;
                        break;
                    }
                }
                if(isfind){
                    cout << i << " " << j << " " << hei << endl;
                    return 0;
                }
            }
        }
    }









}   
