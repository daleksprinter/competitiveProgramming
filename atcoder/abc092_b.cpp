#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int inf = 1001001000;
const int mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
    int n,d,x;
    cin >> n >> d >> x;

    int ans = 0;
    while (n--){
        int t;
        cin >> t;
        ans += d/t + 1;
        if(d%t == 0) ans--;
    }
    cout << ans + x << endl;
}



