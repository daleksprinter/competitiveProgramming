#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <string>
#include <set>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int inf = 1001001000;
const int mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int a, b, k;
    cin >> a >> b >> k;

    set<int> s;

    rep(i, a,min(a+k,b)){
        s.insert(i);
    }

    rep(i, max(a,b-k+1), b+1){
        s.insert(i);
    }

    for(auto e: s) cout << e << endl;
}


