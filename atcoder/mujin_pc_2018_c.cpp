#include <bits/stdc++.h>
using namespace std;

//macro-----------------------------------------------------------------------------------------
#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100000;
const int mod = 1000000007;

//general_method--------------------------------------------------------------------------------
vector<int> cs(vector<int> arr){vector<int> ret = arr;rep(i,1,arr.size()){ret[i] += ret[i-1];}return ret;}

//io_method-------------------------------------------------------------------------------------
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
void print(int n){cout << n << endl;}
void print(vector<int> arr){cout << arr[0];rep(i,1,arr.size()) cout << " " << arr[i];cout << endl;}
void print(string s){cout << s << endl;}

//main_method-----------------------------------------------------------------------------------

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int h = input(), w = input(); 

    char arr[h][w]; rep(i,0,h) rep(j,0,w) cin >> arr[i][j];

    int up[h][w];
    int down[h][w];
    int left[h][w];
    int right[h][w];

    rep(i,0,h){
        rep(j,0,w){
            if(i == 0) up[i][j] = 0;
            else{
                if(arr[i-1][j] == '#' || arr[i][j] == '#') up[i][j] = 0;
                else up[i][j] = up[i-1][j] + 1;
            }
        }
    }

    for(int i = h-1; i > -1; i--){
        rep(j,0,w){
            if(i == h-1) down[i][j] = 0;
            else{
                if(arr[i+1][j] == '#' || arr[i][j] == '#') down[i][j] = 0;
                else down[i][j] = down[i+1][j] + 1;
            }
        }
    }

    for(int j = w-1; j > -1; j--){
        rep(i,0,h){
            if(j == w-1) left[i][j] = 0;
            else{
                if(arr[i][j+1] == '#' || arr[i][j] == '#')left[i][j] = 0;
                else left[i][j] = left[i][j+1] + 1;
            }
        }
    }

    rep(j,0,w){
        rep(i,0,h){
            if(j == 0) right[i][j] = 0;
            else{
                if(arr[i][j-1] == '#' || arr[i][j] == '#') right[i][j] = 0;
                else right[i][j] = right[i][j-1] + 1;
            }
        }
    }

    

    int ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            ans += left[i][j] * up[i][j] + down[i][j] * left[i][j] + right[i][j] * down[i][j] + up[i][j] * right[i][j]; 
        }
    }
    print(ans);


    
}
