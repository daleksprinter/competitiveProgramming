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
#include <ios>     // std::left, std::right
#include <iomanip>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int inf = 1001001000;
//const int mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int digitlen(long long i){
    long long t = i;
    int count = 0;
    while(t){
        count += 1;
        t /= 10;
    }
    return count;
}



int main(){
    int sx,sy,gx,gy,t,v;
    cin >> sx >> sy >> gx >> gy >> t >> v;
    int n;
    cin >> n;

    rep(i,0,n){
        int x;
        int y;
        cin >> x >> y;

        if(sqrt((x - sx) * (x - sx) + (y - sy) * (y - sy)) + sqrt((x - gx) * (x - gx) + (y - gy) * (y - gy)) <= t*v){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}


