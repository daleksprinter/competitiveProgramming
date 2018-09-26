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



//main---------------------------------------------------------------------------------------------------
vector<int> cs(vector<int> arr){vector<int> ret = arr;rep(i,1,arr.size()){ret[i] += ret[i-1];}return ret;}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n,m; cin >> n >> m;

    vector<int> arr(n,0);

    vector<pair<int, int>> section;

    rep(i,0,m){
        int frm, to; cin >> frm >> to; frm--; to--;
        section.push_back(make_pair(frm,to));
        arr[frm]++;
        if(to+1 < n) arr[to+1]--;
    }

    arr = cs(arr);

    rep(i,0,n) if(arr[i] > 1) arr[i] = 0;

    arr = cs(arr);

    vector<int> ans;
    rep(i,0,m){
        pair<int, int> sec = section[i];
        if(arr[sec.second] - (sec.first-1 > -1 ? arr[sec.first-1] : 0) == 0){
            ans.push_back(i+1);
        }
    }
    print((int)ans.size());
    rep(i,0,ans.size()){
        print(ans[i]);
    }

    




}
