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
    int n,m;
    cin >> n;
    map<string,int> mp;

    while(n--){
        string s;
        cin >> s;
        if(mp.find(s) == mp.end()){
            mp.insert(make_pair(s,1));
        }else{
            mp[s] = mp[s] + 1;
        }
    }

    cin >> m;
    while(m--){
        string s;
        cin >> s;
        if(mp.find(s) != mp.end()){
            mp[s] = mp[s] -1;
        }
    }
    int ans = 0;

    for(auto e: mp){
        ans = max(ans,e.second);
    }
    cout << ans << endl;

    
}

