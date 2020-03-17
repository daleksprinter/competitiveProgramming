#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100;
const int mod = 1000000007;

vector<int> cs(vector<int> arr){
    vector<int> ret = arr;
    rep(i,1,arr.size()){
        ret[i] += ret[i-1];
    }
    return ret;
}

//io_method-------------------------------------------------------------------------------------

int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
void print(int n){cout << n << endl;}
void print(vector<int> arr){cout << arr[0];rep(i,1,arr.size()) cout << " " << arr[i];cout << endl;}




//main_method-----------------------------------------------------------------------------------


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n; cin >> n;
    vector<int> arr; rep(i,0,n) arr.push_back(input());
    sort(arr.begin(), arr.end());

    vector<int> combright(n);
    rep(i,0,n){
        combright[i] = distance(lower_bound(arr.begin(), arr.end(), arr[i]*2), arr.end());
    }

    combright = cs(combright);

    int ans = 0;
    rep(i,0,n-1){
        int left = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), arr[i]/2 + 1));
        int right = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), arr[i] * 2));
        ans += left * (combright[n-1] - combright[right-1]);
        ans %= mod;

    }

    print(ans);
    





}
