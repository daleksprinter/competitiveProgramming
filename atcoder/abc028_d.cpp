#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int main(){
    double n, k;
    cin >> n >> k;
    cout << fixed << setprecision(10) <<((k-1)*(n-k)*6 + (k-1)*3 + (n-k)*3 + 1)/n/n/n << endl;;
}
