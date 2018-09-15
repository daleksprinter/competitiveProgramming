#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> arr;
    rep(i,0,n){
        int t;
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(),arr.end());

    int cnt = 0;

    int i = 0;
    while (i < n &&x-arr[i] >= 0 ){
        cnt++;
        x-= arr[i];
        i++;
        
    }

    if(x == 0 && i == n){
        cout << cnt << endl;
    }else if(x== 0 && i <= n){
        cout << cnt << endl;
    }else if(i < n && x > 0){

        cout << cnt << endl;
    }else if(x > 0){
        cout << cnt -1 << endl;
    }else{
        cout << cnt << endl;
    }


}
