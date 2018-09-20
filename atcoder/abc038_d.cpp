#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100009;
const int mod = 1000000007;

int maxw = 100001;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first != b.first) return a.first < b.first;
    else return b.second < a.second;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n; cin >> n;

    vector<pair<int, int>> box;

    rep(i,0,n){
        int w,h; cin >> w >> h;
        box.push_back(make_pair(w,h));
    }

    sort(box.begin(), box.end(), comp);
    
    vector<int> lis(maxw,inf);
    
    rep(i, 0, box.size()){
        lis[distance(lis.begin(), lower_bound(lis.begin(), lis.end(), box[i].second) )] = box[i].second;
    }


    int ans = 0;
    while(lis[ans] < inf) ans++;

    cout << ans << endl;

    



}
