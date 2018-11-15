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


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = pow(2, 62);
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


vector<int> dijkstra(int s, vector< vector<pair<int,int>>> l, int v){
    vector<int> dist; rep(i,0,v) dist.push_back(inf); dist[s] = 0;
    priority_queue< pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> que; que.push(make_pair(0,s));
 
    while(!que.empty()){
        pair<int,int> p = que.top(); que.pop();
        int vertex = p.second;
        if(dist[vertex] < p.first) continue;
        rep(i,0,l[vertex].size()){
            pair<int,int> to = l[vertex][i];
            if(dist[to.second] > dist[vertex] + to.first){
                dist[to.second] = dist[vertex] + to.first;
                que.push(make_pair(dist[to.second],to.second));
            }
        }
     
    }
    return dist;
}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;

    vec<vec<pi>> edges(n, vec<pi>());

    rep(i,0,k){
        int q; cin >> q;
        if(q){
            int f, t, dist; cin >> f >> t >> dist; f--; t--;
            edges[f].push_back(pi(dist, t));
            edges[t].push_back(pi(dist, f));
        }else{
            int f, t; cin >> f >> t; f--; t--;
            vi dist = dijkstra(f, edges, n);
            if(dist[t] == inf){
                print(-1);
            }else{
                print(dist[t]);
            }
        }
    }

    


    




    




    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









