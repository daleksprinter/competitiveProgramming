#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;


vector < vector<int> > sub;
int n;

int rev(int i){
    if(sub[i].size() == 0){
        return 1;
    }else{
        vector<int> subrev;
        rep(j,0,sub[i].size()){
            subrev.push_back(rev(sub[i][j]));
        };
        return *max_element(subrev.begin(),subrev.end()) + *min_element(subrev.begin(),subrev.end()) + 1;
    }
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    rep(i,0,n){
        vector<int> t;
        sub.push_back(t);
    }
    

    rep(i,1,n){
        int t; cin >> t;
        sub[t-1].push_back(i);
    }

    cout << rev(0) << endl;

}
