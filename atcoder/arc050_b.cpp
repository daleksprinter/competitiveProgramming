#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i=a;i>b;i--)
#define int long long

const int inf = 100100100100000;
const int mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
void print(int n){cout << n << endl;}
void print(vector<int> arr){cout << arr[0];rep(i,1,arr.size()) cout << " " << arr[i];cout << endl;}
void print(string s){cout << s << endl;}
void print(pair<int, int> p){cout << p.first << " " << p.second;}
void print(vector<vector<int>> arr){rep(i,0,arr.size()){print(arr[i]);}}
void print(double n){cout << n << endl;}



//main---------------------------------------------------------------------------------------------------
int a,b;
int x,y;

bool isok(int t){
    if(a-t < 0 || b-t < 0)return false;
    return (a-t)/(x-1) + (b-t)/(y-1) >= t;
}


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> a >> b;
    cin >> x >> y;

    int left = 0;
    int right = pow(10,18);

    rep(i,0,1000){
        int mid = (left + right)/2;
        if(right - left <= 1) break;
        if(isok(mid)){
            left = mid;
        }else{
            right = mid;
        }
    }

    print(left);


}
