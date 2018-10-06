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

int n, m; 
bool isok(int t){
    if(m/t >= n){
        return true;
    }else{
        return false;
    }
}

signed main(){


    
    cin >> n >> m;

    vector<int> facts = factors(m);
    
    sort(facts.begin(), facts.end());

    int left = 0;
    int right = facts.size();

    rep(i,0,100){
        int mid = (left + right)/2;

        if(isok(facts[mid])){
            left = mid;
        }else{
            right = mid;
        }
    }
    print(facts[left]);
    













}   
