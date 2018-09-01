#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> arr;
    int i = n;
    while (i--){
        int t;
        cin >> t;
        arr.push_back(t);
    }
    cout << n + (x - accumulate(arr.begin(),arr.end(),0)) / *min_element(arr.begin(),arr.end()) << endl;
}

