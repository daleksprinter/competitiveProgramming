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

    int buff = 0;
    int left = 0;
    int right = 0;
    int ans = 0;

    while(left < n){

        if(right < n && (buff ^ arr[right]) == buff + arr[right]){
            buff += arr[right];
            right++;
            
        }else{
            ans += right - left;
            buff -= arr[left];
            left++;
        }
    }
    
    cout << ans << endl;
    
}   
