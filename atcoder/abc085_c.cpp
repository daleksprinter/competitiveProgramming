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





int main(){
    int x,y;
    cin >> x >> y;

    rep(i,0,x+1){
        rep(j,0,x-i+1){
            if(10000*i + 5000*j + 1000*(x-i-j) == y){
                cout << i << " " << j << " " << x-i-j << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}


