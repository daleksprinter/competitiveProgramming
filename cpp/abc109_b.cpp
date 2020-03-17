#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll inf = 100100100100100;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;
    vector<string> w;

    string s;
    cin >> s;
    w.push_back(s);
    n--;
    while(n--){
        string t;
        cin >> t;
        rep(i,0,w.size()){
            if(w[i] == t) {
                cout << "No" << endl;
                return 0;
            }
        }

        if(w[w.size()-1].back() != t[0]){
            cout << "No" << endl;
            return 0;
        }
        w.push_back(t);
    }
    cout << "Yes" << endl;

}
