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

int digitsum(int i){
    int t = i;
    int ret = 0;
    while(t){
        ret += t%10;
        t /= 10;
    }
    return ret;
}

int main(){
    int h,w;
    cin >> h >> w;
    while(h--){
        string s;
        cin >> s;
        cout << s << endl;
        cout << s << endl;
    }
}


