#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    int i = m;
    vector<int> arr;
    while(i--){
        int t;
        cin >> t;
        arr.push_back(t);
    }
    int count = 0;
    for(int i = 0; i < m; i++){
        if(arr[i] > x){
            count++;
        }
    }
    int count2 = 0;
    for(int i = 0; i < m; i++){
        if(arr[i] < x){
            count2++;
        }
    }
    cout << min({count,count2}) << endl;

}
