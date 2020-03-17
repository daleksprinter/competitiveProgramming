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

int h,w;
char c[50][50];
int cost[50][50];

int main(){
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    rep(i,0,a){
        if(!isdigit(s[i])){
            cout << "No" << endl;
            return 0;
        }
    }
    if(s[a] != '-'){
        cout << "No" << endl;
        return 0;
    }

    rep(i,a+1,a+1+b){
        if(!isdigit(s[i])){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}

