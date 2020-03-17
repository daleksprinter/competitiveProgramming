#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int x;
    cin >> x;
    int ans = 1;
    for(int i = 2; i < x; i++){
        int j =  2;
        while (pow(i,j) <= x){
            int t = pow(i,j);
            ans = max({ans, t});
            j++;
        }
    }
    cout << ans << endl;
}
