#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll inf = 100100100100100;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a,b;
    cin >> a >> b;
    if(a*b %2 == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}
