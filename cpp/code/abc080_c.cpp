#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
typedef long long ll;
const ll inf = 100100100100100;
const int mod = 1000000007;


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n; cin >> n;

    int open[n][10];
    rep(i,0,n) rep(j,0,10) cin >> open[i][j];

    int revenue[n][11];
    rep(i,0,n) rep(j,0,11) cin >> revenue[i][j];

    int ans = inf * -1;

    rep(i,1,pow(2,10)){
        int tmp = 0;
        rep(j,0,n){
            int count = 0;
            rep(k,0,10){
                if(i & (1<<k) && open[j][k] == 1){
                    count++;
                }
            } 
            tmp += revenue[j][count];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;


}
