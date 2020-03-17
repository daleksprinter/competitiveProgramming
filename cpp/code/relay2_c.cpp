#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector< pair<int,int> > arr;
    rep(i,0,n){
        int w,d;
        cin >> w >> d;
        arr.push_back(make_pair(w,d));
    }

    int left = 0;
    int right = 3e18;
    rep(i,0,200){
        int mid = (left + right)/2;
        int cnt = 0;
        
        rep(j,0,n){
            if (mid < arr[j].first) continue;
            cnt += (mid - arr[j].first)/arr[j].second + 1;
        }

        if(cnt >= k){
            right = mid;
        }else{
            left = mid+1;
        }
    }

    cout << left << endl;
}
