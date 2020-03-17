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
#define sz(v) (int)v.size()
#define fir first
#define sec second



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
template<typename T> auto cut(T &a, int l, int r){return T(a.begin()+l, a.begin()+r);}

/* main */
pair<vi, vi> dijkstra(int s, vec<vec<pi>> edges, int n){
    vi dist(n, inf); dist[s] = 0;
    vi parent(n, -1);
    priority_queue<pi, vec<pi>, greater<pi>> q;
    q.push(pi(0, s));

    while(!q.empty()){
        pi p = q.top(); q.pop();
        int v = p.sec;

        if(dist[v] < p.first) continue;

        for(pi to : edges[v]){
            if(dist[to.sec] > dist[v] + to.fir){
                dist[to.sec] = dist[v] + to.fir;
                parent[to.sec] = v;
                q.push(pi(dist[to.sec], to.sec));
            }
        }
    }

    return pair<vi, vi>(dist, parent);

}

string f, t;
int n;
vec<string> arr;

vec<vec<pi>> edges(1010);


signed main(){


    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> f >> t >> n;
    arr.push_back(f);
    rep(i,0,n) arr.push_back(raw_input());
    arr.push_back(t);

    if(f == t){
        print(0);
        print(f);
        print(f);
        return 0;
    }

    rep(i,0,n + 2){
        rep(j,0,n + 2){
            if(i == j) continue;
            int cnt = 0;
            rep(k,0,sz(f)){
                if(arr[i][k] != arr[j][k]) cnt++;
            }
            if(cnt == 1) edges[i].push_back(pi(1, j));
        }
    }

    auto ans = dijkstra(0, edges, n + 2);

    if(ans.first.back() == inf){
        print(-1);
        return 0;
    }

    print(ans.first.back() - 1);
    int i = n + 1;
    vec<string> pr;

    while(ans.second[i] != -1){
        pr.push_back(arr[i]);
        i = ans.second[i];
    }

    pr.push_back(arr[0]);
    reverse(all(pr));

    rep(i,0,sz(pr)){
        print(pr[i]);
    }



    



	
	

	



	
	


	




	




    



	








    



    





    


    

}


