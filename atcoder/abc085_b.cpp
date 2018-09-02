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

int digitlen(int i){
    int t = i;
    int count = 0;
    while(t){
        count++;
        t /= 10;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    set<int> s;
    while(n--){
        int t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size() << endl;
}

