#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

int mod_pow(int x, int n, int m){
    if(n== 0) return 1;
    int res = mod_pow(x*x%m,n/2,m);
    if(n&1) res = res*x%m;
    return res;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string s;
    cin >> s;
    int len = s.size();

    vector<int> acs;
    acs.push_back(0);
    vector<int> lcs;
    lcs.push_back(0);

    vector<int> ccs;
    ccs.push_back(0);
    vector<int> rcs;
    rcs.push_back(0);

    rep(i,0,len){
        if(s[i] == 'A'){
            acs.push_back(acs.back()+1);
            lcs.push_back(lcs.back());
        }
        else if(s[i] == '?'){
            lcs.push_back(lcs.back()+1);
            acs.push_back(acs.back());
        }
        else{
            acs.push_back(acs.back());
            lcs.push_back(lcs.back());
        }
    }

    for(int i = len-1; i > -1; i--){
        if(s[i] == 'C'){
            ccs.push_back(ccs.back()+1);
            rcs.push_back(rcs.back());
        }
        else if(s[i] == '?'){
            rcs.push_back(rcs.back()+1);
            ccs.push_back(ccs.back());
        }
        else{
            ccs.push_back(ccs.back());
            rcs.push_back(rcs.back());
        }
    }

    reverse(ccs.begin(),ccs.end());
    reverse(rcs.begin(),rcs.end());

    int ans = 0;
    rep(i,0,len){
        if(s[i] == 'B' || s[i] == '?'){
            ans += acs[i]%mod * ccs[i+1]%mod * mod_pow(3, lcs[i] + rcs[i+1],mod);
            ans += lcs[i]%mod * ccs[i+1]%mod * mod_pow(3, lcs[i] + rcs[i+1] - 1,mod);
            ans += acs[i]%mod * rcs[i+1]%mod * mod_pow(3, lcs[i] + rcs[i+1] - 1,mod);
            ans += lcs[i]%mod * rcs[i+1]%mod * mod_pow(3, lcs[i] + rcs[i+1] - 2,mod);
            ans %= mod;
        }
    }
    cout << ans % mod << endl;
}
