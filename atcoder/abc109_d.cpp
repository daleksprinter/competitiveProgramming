#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll inf = 100100100100100;

int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b,a%b);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    
    int h,w;
    cin >> h >> w;
    int arr[h][w];
    rep(i,0,h){
        rep(j,0,w){
            cin >> arr[i][j];
        }
    }
    
    vector<string> out;
    rep(i,0,h){
        rep(j,1,w){
            if(arr[i][j-1] % 2 == 1){
                arr[i][j-1]--;
                arr[i][j]++;
                string t = "";
                t += to_string(i+1) + " " + to_string(j) + " " + to_string(i+1) + " " + to_string(j+1);
                out.push_back(t);
            }
        }
    }

 
    rep(i,1,h){
        if(arr[i-1][w-1] %2 == 1){
            arr[i-1][w-1]--;
            arr[i][w-1]++;
            string t = "";
            t += to_string(i) + " " + to_string(w) + " " + to_string(i+1) + " " + to_string(w);
            out.push_back(t);
        }
    }
 
    cout << out.size() << endl;
    rep(i,0,out.size()) cout << out[i] << endl;

}
