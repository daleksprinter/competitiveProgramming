#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

int ceil(int a, int b){
    if(a%b == 0){
        return a/b;
    }else{
        return a/b + 1;
    } 
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int h,w;
    cin >> h >> w;
    cout << (h-1)* w + (w-1) * h << endl;
}
