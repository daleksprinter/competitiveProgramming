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



vector<vector<int>> arr(10, vector<int>(10));

vector<vector<int>> cop;

void bfs(int x,int y){
    cop[y][x] = 0;
    rep(i,0,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(-1 < nx && nx < 10 && -1 < ny && ny < 10 && cop[ny][nx] == 1){
            bfs(nx, ny);
        }
    }
}



signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    rep(i,0,10){
        rep(j,0,10){
            char c; cin >> c;
            if(c == 'o'){
                arr[i][j] = 1;
            }else{
                arr[i][j] = 0;
            }
        }
    }

    
    rep(i,0,10){
        rep(j,0,10){
            cop = arr;
            cop[i][j] = 1;
            int cnt = 0;
            rep(k,0,10){
                rep(l,0,10){
                    if(cop[k][l] == 1){
                        bfs(l,k);
                        cnt++;
                    }
                }
            }
            if(cnt == 1){
                print("YES");
                return 0;
            }
        }
    }
    print("NO");
    return 0;


}
