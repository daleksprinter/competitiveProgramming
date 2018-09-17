#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100009;
const int mod = 1000000007;


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);


    int w, n, k; cin >> w >> n >> k;

    vector<pair<int,int>> arr;
    rep(i,0,n){
        int a, b; cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }

    int dp[k+1][w+1]; rep(i,0,k+1) rep(j,0,w+1) dp[i][j] = -1; dp[0][0] = 0;

    rep(t, 0, n){
        for(int i = k; i > 0; i--){
            rep(j, 0, w+1){
                if(j - arr[t].first > -1 && dp[i-1][j - arr[t].first] >= 0){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-arr[t].first] + arr[t].second );
                }
            }
        }
    }


    int ans = 0;
    rep(i,0,k+1){
        rep(j,0,w+1){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;



}
