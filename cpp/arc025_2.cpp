#include <bits/stdc++.h>
using namespace std;

//macro-----------------------------------------------------------------------------------------
#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100000;
const int mod = 1000000007;

//general_method--------------------------------------------------------------------------------
vector<int> cs(vector<int> arr){vector<int> ret = arr;rep(i,1,arr.size()){ret[i] += ret[i-1];}return ret;}
int ceil(int a, int b){if(a%b == 0) return a/b;else return a/b + 1;}
int digitlen(int i){int t = i;int count = 0;while(t){count += 1;t /= 10;}return count;}
int gcd(int m, int n){if((0== m)||(0 == n))return 0;while(m != n){if(m > n)m = m - n;else n = n - m;}return m;}
int lcm(int n, int m){return n*m/gcd(n,m);}

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

    int h, w; cin >> h >> w;

    int white[h][w]; memset(white, 0, sizeof(white));
    int black[h][w]; memset(black, 0, sizeof(black));

    rep(i,0,h){
        rep(j,0,w){
            if((i+j)%2 == 0) white[i][j] = input();
            else black[i][j] = input(); 
        }
    }

    rep(i,1,h){
        rep(j,0,w){
            white[i][j] += white[i-1][j];
            black[i][j] += black[i-1][j];
        }
    }

    rep(j,1,w){
        rep(i,0,h){
            white[i][j] += white[i][j-1];
            black[i][j] += black[i][j-1];
        }
    }

    int ans = 0;
    rep(top_i, 0, h){
        rep(bottom_i, top_i, h){
            rep(left_j, 0, w){
                rep(right_j, left_j, w){
                    int w_cnt = white[bottom_i][right_j] - (top_i - 1 > -1 ? white[top_i-1][right_j] : 0) - (left_j - 1 > -1 ? white[bottom_i][left_j -1] : 0) + (top_i-1 > -1 && left_j-1 > -1 ? white[top_i-1][left_j-1] : 0);
                    int b_cnt = black[bottom_i][right_j] - (top_i - 1 > -1 ? black[top_i-1][right_j] : 0) - (left_j - 1 > -1 ? black[bottom_i][left_j -1] : 0) + (top_i-1 > -1 && left_j-1 > -1 ? black[top_i-1][left_j-1] : 0);
                    if(w_cnt == b_cnt) ans = max(ans, (bottom_i - top_i + 1) * (right_j-left_j + 1));
                }
            }
        }
    }
    print(ans);



    
    




    






}
