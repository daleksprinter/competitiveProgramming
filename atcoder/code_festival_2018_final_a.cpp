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
template<typename T>
auto cut(T &a, int l, int r){
    //get a[l:r]
    return T(a.begin()+l, a.begin()+r);   
}



signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vec<vi> edges(n);

	rep(i,0,m){
		int f, t, d; cin >> f >> t >> d;
		f--; t--;
		edges[f].push_back(d);
		edges[t].push_back(d);
	}

	int ans = 0;
	rep(i,0,n){
		sort(all(edges[i]));
		int cnt = 0;
		rep(j,0,edges[i].size()){
			int d = edges[i][j];
			cnt += upper_bound(all(edges[i]), 2540 - d) - lower_bound(all(edges[i]), 2540 - d);
			if(d == 1270) cnt--;
		}

		ans += cnt;
	}

	print(ans / 2);




	

	



	
	


	




	




    



	








    



    





    


    

}


