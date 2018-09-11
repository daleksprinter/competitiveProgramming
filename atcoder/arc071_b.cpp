#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n,m; 
    cin >> n >> m;

    int x[n]; 
    rep(i,0,n) cin >> x[i];
    int y[m]; 
    rep(i,0,m) cin >> y[i];

    int sumx = 0;
    int sumy = 0;

    rep(i,0,n) sumx = (sumx + (i * 2 + 1 - n) * x[i]) % mod;
	rep(i,0,m) sumy = (sumy + (i * 2 + 1 - m) * y[i]) % mod;

    cout << sumx * sumy % mod << endl;
    return 0;


}
