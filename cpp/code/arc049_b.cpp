#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

int n;
vector < vector<double> > arr;

bool isok(double t){
    rep(i,0,n){
        double xi = arr[i][0], yi = arr[i][1], ci = arr[i][2];
        rep(j,i,n){
            double xj = arr[j][0], yj = arr[j][1], cj = arr[j][2];
            if(abs(xi - xj) > t/ci + t/cj || abs(yi - yj) > t/ci + t/cj) return false;
        }
    }
    return true;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;

    
    rep(i,0,n){
        double x, y, c;
        cin >> x >> y >> c;
        arr.push_back({x, y, c});
    }

    double left = 0;
    double right = 999999999;
    rep(i,0,100){
        
        double mid = (left + right)/2;
        if(isok(mid)){
            right = mid;
        }else{
            left = mid;
        }

    }
    printf("%.10lf\n", right);

    return 0;

}
