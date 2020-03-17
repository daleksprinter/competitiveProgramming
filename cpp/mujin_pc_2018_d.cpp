#include "bits/stdc++.h"
using namespace std;

/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))
#define pb push_back


/* alias */


template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 1000100010010010;
const int mod = 1e9 + 7;
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};
const string alpha = "abcdefghijklmnopqrstuvwxyz";

/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
template<class T> void printx(T n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";each(s, e){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";each(mp, e){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }




/* main */

vec<pi> graph[1000][1000];

int rev(int n){
    string r = to_string(n);
    reverse(all(r));
    return stoi(r);
}

bool visited[1000][1000];
int n, m;

void dfs(int x, int y){

    if(visited[x][y]) return;

    visited[x][y] = true;

    rep(i,0,graph[x][y].size()){
        pi e = graph[x][y][i];
        dfs(e.first, e.second);
    }
    
    return;

}


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);


    cin >> n >> m;

    rep(x,1,1000){
        rep(y,1,1000){
           
                int nx = x, ny = y;
                if(nx < ny){
                    nx = rev(nx);
                }else{
                    ny = rev(ny);
                }

                if(nx < ny){
                    ny = ny - nx;
                }else{
                    nx = nx - ny;
                }

                graph[nx][ny].push_back(pi(x, y));
            
        }
    }
    

    memset(visited, false, sizeof(visited));



    rep(i,0,1000){
        dfs(i, 0);
    }

    rep(i,0,1000){
        dfs(0, i);
    }


    int ans = 0;
    rep(i,1,n + 1){
        rep(j,1,m + 1){
            if(not visited[i][j]) ans++;
        }
    }

    print(ans);


    

    


    




    
    
    

    



    






    



    





    


    

}


