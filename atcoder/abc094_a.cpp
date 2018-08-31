#include <iostream>
using namespace std;
int main(){
    int a,b,x;
    cin >> a >> b >> x;
    if(b >= x - a && a <= x){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
