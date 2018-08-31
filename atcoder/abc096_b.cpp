#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int a,b,c,n;
    cin >> a >> b >> c;
    cin >> n;

    cout << pow(2,n) * max({a,b,c}) + a + b + c - max({a,b,c}) << endl;

}
