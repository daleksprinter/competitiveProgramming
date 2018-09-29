#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i=a;i>b;i--)
#define int long long

const int inf = 100100100100000;
const int mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
void print(int n){cout << n << endl;}
void print(vector<int> arr){cout << arr[0];rep(i,1,arr.size()) cout << " " << arr[i];cout << endl;}
void print(string s){cout << s << endl;}
void print(pair<int, int> p){cout << p.first << " " << p.second;}
void print(vector<vector<int>> arr){rep(i,0,arr.size()){print(arr[i]);}}
void print(double n){cout << n << endl;}
int ceil(int a, int b){if(a%b == 0) return a/b;else return a/b + 1;}

//main-----------------------------------------------------------------------------


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n = input();

    vector<int> arr; rep(i,0,n) arr.push_back(input());

    vector<pair<int, int>> a;
    vector<pair<int, int>> b;

    rep(i,0,100001){
        a.push_back(make_pair(0, i));
        b.push_back(make_pair(0, i));
    }

    rep(i,0,n){
        if(i % 2 == 0) a[arr[i]].first++;
        else{ b[arr[i]].first++;}
    }

    sort(a.begin(), a.end(), greater<pair<int, int>>());
    sort(b.begin(), b.end(), greater<pair<int, int>>());

    if(a[0].second == b[0].second){
        print(min(n - a[0].first - b[1].first, n - a[1].first - b[0].first));

    }else{
        print(n - a[0].first - b[0].first);
    }





}
