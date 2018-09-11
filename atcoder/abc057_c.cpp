#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

int digitlen(int i){
    int t = i;
    int count = 0;
    while(t){
        count += 1;
        t /= 10;
    }
    return count;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;
    int ans = 100;
    rep(i,1,(int)sqrt(n)+1){
        if(n%i == 0){
            ans = min(ans, digitlen(n/i));
        }
    }
    cout << ans << endl;
}
