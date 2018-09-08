#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll inf = 100100100100100;

int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b,a%b);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    
    int n,x;
    cin >> n >> x;

    vector<int> arr;
    rep(i,0,n){
        int t;
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(),arr.end());
    arr.insert(lower_bound(arr.begin(),arr.end(),x),x);
    
    vector<int> sub;
    rep(i,1,n+1) sub.push_back(arr[i] - arr[i-1]);
    int g = sub[0];
    rep(i,1,n) g = gcd(g,sub[i]);
    cout << g << endl;


}
