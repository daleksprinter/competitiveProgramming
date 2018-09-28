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


//main-----------------------------------------------------------------------------
int n, m;
int edges[16];
int dp[1<<16];


int dfs(int s){
    if(dp[s] > -1) return dp[s];
    
    if(s == (1<<n)-1){
        return 1;
    }

    int comb = 0;
    rep(i,0,n){
        if(!(s & (1 << i)) && ((edges[i] & s) == 0)){ 
           comb += dfs(s + (1<<i));
        }
    }

    return dp[s] = comb;

}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    memset(edges, 0, sizeof(edges));


    rep(i,0,m){
        int t,f; cin >> t >> f; t--; f--;
        edges[f] += (1<<t);
    }
    

    memset(dp, -1, sizeof(dp));
    

    print(dfs(0));





}
