#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;



signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n,q;
    cin >> n >> q;

    rep(i,0,q){
        int a,b;
        cin >> a >> b;

        if(n==1){
            cout << min(a,b) << endl;
            continue;
        }
        while(a != b){
            if( a > b ){
                a = (a+n-2)/n;
            }else{
                b = (b+n-2)/n;
            }
        }

        if(a == 0) cout << 1 << endl;
        else cout << a << endl;

    }

}
