#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100009;
const int mod = 1000000007;

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n; cin >> n;
    int arr[n]; rep(i,0,n) cin >> arr[i];

    int left = 0;
    int mid = 1;

    int ans = 0;
    while(mid < n-2){
        if(arr[mid-1] > arr[mid] && arr[mid] < arr[mid+1]) {
            ans = max(ans, mid - left + 1);
            left = mid;
        }
        mid++;
    }
    ans = max(ans, (n-1) - left + 1);
    cout << ans << endl;
}   
