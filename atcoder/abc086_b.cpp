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
    int a,b;
    cin >> a >> b;
    a = a * pow(10, digitlen(b)) + b;
    for(int i = 0; i < sqrt(a)+1; i++){
        if(a == i*i){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}


