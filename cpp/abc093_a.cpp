#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <string>
using namespace std;
int main(){
    string str;
    cin >> str;
    if(str.find("a") != string::npos && str.find("b") != string::npos && str.find("c") != string::npos){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}

