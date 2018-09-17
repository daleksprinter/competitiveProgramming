#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100009;
const int mod = 1000000007;


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, ma, mb; cin >> n >> ma >> mb;

    vector<vector<int> > arrf;
    vector<vector<int> > arrs;
    rep(i,0,n/2){
        int a, b, cost;
        cin >> a >> b >> cost;
        vector<int> tmp = {a, b, cost};
        arrf.push_back(tmp); 
    }

    rep(i,n/2,n){
        int a, b, cost;
        cin >> a >> b >> cost;
        vector<int> tmp = {a, b, cost};
        arrs.push_back(tmp); 
    }

    vector< vector<int> > fir;
    rep(i,0,pow(2,arrf.size())){
        int asum = 0, bsum = 0, csum = 0;
        rep(j,0,arrf.size()){
            if(i & (1 << j)){
                asum += arrf[j][0]; bsum += arrf[j][1]; csum += arrf[j][2];
            }
        }
        vector<int> tmp = {asum, bsum, csum}; fir.push_back(tmp);
    }

    map<pair<int, int> , int> mp;
    rep(i,0,pow(2,arrs.size())){
        int asum = 0, bsum = 0, csum = 0;
        rep(j,0,arrs.size()){
            if(i & (1 << j)){
                asum += arrs[j][0]; bsum += arrs[j][1]; csum += arrs[j][2];
            }
        }
        pair<int, int> key = make_pair(asum, bsum); 
        
        if(mp.find(key) == mp.end()){ //not found
            mp[key] = csum;
        }else{
            mp[key] = min(mp[key], csum);
        }
    }

    int ans = inf;
    rep(i,0, fir.size()){
        rep(j,1,15){
            pair<int, int> key = make_pair(ma * j - fir[i][0], mb * j - fir[i][1]);
            if(mp.find(key) == mp.end()){
                continue;
            }else{
                ans = min(ans, fir[i][2] + mp[key]);
            }
        }
    }

    if(ans == inf){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;






}
