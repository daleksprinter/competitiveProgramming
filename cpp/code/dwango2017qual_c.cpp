#include <bits/stdc++.h>
using namespace std;

//macro-----------------------------------------------------------------------------------------
#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100000;
const int mod = 1000000007;

//general_method--------------------------------------------------------------------------------
vector<int> cs(vector<int> arr){vector<int> ret = arr;rep(i,1,arr.size()){ret[i] += ret[i-1];}return ret;}

//io_method-------------------------------------------------------------------------------------
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
void print(int n){cout << n << endl;}
void print(vector<int> arr){cout << arr[0];rep(i,1,arr.size()) cout << " " << arr[i];cout << endl;}
void print(string s){cout << s << endl;}

//main_method-----------------------------------------------------------------------------------

int ceil(int a, int b){
    if(a%b == 0) return a/b;
    else return a/b + 1;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n = input();
    vector<int> arr; rep(i,0,n) arr.push_back(input());

    vector<int> cnt(5,0); for(auto e: arr) cnt[e]++;

    int ans = 0;
    ans += cnt[4];
    ans += cnt[3];
    cnt[1] = max((int)0, cnt[1] - cnt[3]);

    ans += ceil(cnt[2],2);
    cnt[1] = max((int)0, cnt[1] - cnt[2]%2*2);
    ans += ceil(cnt[1],4);

    print(ans);

    
}
