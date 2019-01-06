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

int n, w;
int weight[100];
int value[100];
int dp[100][100010];

int dfs(int i, int sum){

	if(i == n) return 0;

	if(dp[i][sum] > -1) return dp[i][sum];

	int ans = 0;

	if(weight[i] <= w - sum) 
		chmax(ans, value[i] + dfs(i + 1, sum + weight[i]));

	chmax(ans, dfs(i + 1, sum));

	return dp[i][sum] = ans;


}



signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

	cin >> n >> w;
	rep(i,0,n){
		int wei, val; cin >> wei >> val;
		weight[i] = wei;
		value[i] = val;
	}

	memset(dp, -1, sizeof(dp));

	print(dfs(0, 0));



	




	




    



	








    



    





    


    

}


