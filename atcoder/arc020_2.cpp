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


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);


   int n, c; cin >> n >> c;

   vector<int> arr; rep(i,0,n) arr.push_back(input());

   int ans = inf;

   rep(i,1,11){
       rep(j,1,11){
            if( i == j ) continue;
            int cost = 0;
            rep(k,0,n){
                if(k % 2 == 0 && arr[k] != i) cost += c;
                if(k % 2 == 1 && arr[k] != j) cost += c;
            }

            ans = min(ans, cost);

       }
   }

   print(ans);

}
