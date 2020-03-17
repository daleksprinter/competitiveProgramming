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
    int n;
    cin >> n;
    vector<int> arr;
    while(n--){
        int t;
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(),arr.end(),greater<int>());
    int a = 0;
    int b = 0;
    rep(i,0,arr.size()){
        if(i%2 ==0){
            a += arr[i];
        }else{
            b += arr[i];
        }
    }
    cout << a-b << endl;
}
