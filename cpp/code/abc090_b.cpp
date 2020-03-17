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
    int a,b;
    cin >> a >> b;
    int count = 0;
    rep(i,a,b+1){
        vector<int> arr;
        int t = i;
        while(t){
            arr.push_back(t%10);
            t /= 10;
        }
        bool istrue = true;
        rep(j,0,2){
            if(arr[j] != arr[4-j]){
                istrue = false;
            }
        }

        if(istrue) count++;
    }
    cout << count << endl;
}



