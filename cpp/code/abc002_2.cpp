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
 
    string s;
    cin >> s;

    string ans = "";

    for(char e: s){
        if(e == 'a' || e== 'i' || e == 'u' || e == 'e' || e == 'o'){
            continue;
        }else{
            ans += e;
        }
    }

    cout << ans << endl;

}
