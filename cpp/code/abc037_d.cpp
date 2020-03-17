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
int h,w;
int arr[1000][1000];
int dp[1000][1000];

int bfs(int y, int x){
    if(dp[y][x] > -1) return dp[y][x];

    int comb = 1;
    rep(i,0,4){
        int nx = x + dx[i]; int ny = y + dy[i];
        if(-1 < nx and nx < w and -1 < ny and ny < h && arr[ny][nx] < arr[y][x]){
            comb += bfs(ny, nx)%mod;
        }
    }
    return dp[y][x] = comb%mod;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> h >> w;
    rep(i,0,h){
        rep(j,0,w){
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            ans += bfs(i,j)%mod;
        }
    }

    print(ans%mod);
   





}
