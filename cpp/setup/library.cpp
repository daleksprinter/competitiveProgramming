
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
#define sec second
#define fir first
#define sz(v) (int)v.size()
/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef set<int> si;
/* constant */
//const int inf = pow(2, 62);
const int inf = pow(2, 30);
const int mod = 1e9 + 7;
//int dx[8]={1,0,-1,0,-1,1,-1,1};
//int dy[8]={0,1,0,-1,-1,-1,1,1};
int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};
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

struct Union_Find{
    vector<int> par;
    vector<int> rank;

    Union_Find(int n){
        for(int i = 0; i < n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int root(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = root(par[x]);
        }
    }

    void merge(int x, int y){
        x = root(x);
        y = root(y);

        if(x == y) return;

        if(rank[x] < rank[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    mi comp(){
        mi ret;
        rep(i,0,sz(par)) ret[root(i)]++;
        return ret;
    }

    

};


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}


vector<int> factors(int n){
    vector<int> facts;
    int i = 1;
    while(i*i < n){
        if(n % i == 0){
            facts.push_back(i);
            facts.push_back(n/i);
        }
        i++;
    }
    int sq = (int)sqrt(n);
    if(sq * sq == n) facts.push_back(sq);
    sort(all(facts));
    return facts;
}

vector<vector<int>> warshaint_floyd(vector<vector<int>> edges,int v){
    vector<vector<int>> ret = edges;
    rep(k,0,v){
        rep(i,0,v){
            rep(j,0,v){
                if(ret[i][k] == inf || ret[k][j] == inf) continue;
                ret[i][j] = min(ret[i][j],ret[i][k] + ret[k][j]);
            }
        }
    }
    return ret;
}

int mod_pow(int x, int n, int m){
    if(n== 0) return 1;
    int res = mod_pow(x*x%m,n/2,m);
    if(n&1) res = res*x%m;
    return res;
}

int factorial(int x){
    int res = 1;
    rep(i,2,x+1){
        res *= i;
        res %= mod;
    }
    return res;
}

int inv(int n){
    return mod_pow(n,mod-2,mod);
}

vi dijkstra(int s, vec<vec<pi>> edges, int n){
    vi dist(n, inf); dist[s] = 0;
    priority_queue<pi, vec<pi>, greater<pi>> q;
    q.push(pi(0, s));

    while(!q.empty()){
        pi p = q.top(); q.pop();
        int v = p.sec;

        if(dist[v] < p.first) continue;

        for(pi to : edges[v]){
            if(dist[to.sec] > dist[v] + to.fir){
                dist[to.sec] = dist[v] + to.fir;
                q.push(pi(dist[to.sec], to.sec));
            }
        }
    }

    return dist;

}


struct bellman_ford{
    vector<int> distance;
    bool is_negative_loop;
 
    bellman_ford(vector<vector<int> > edges, int s, int n){
        vector<int> dist;
        rep(i,0,n) dist.push_back(inf); dist[s] = 0;
         
        rep(i,0,n){
            bool isupdate = false;
            rep(j,0,edges.size()){
                int frm = edges[j][0], to = edges[j][1], cost = edges[j][2];
                if(dist[frm] != inf && dist[to] > dist[frm] + cost){
                    dist[to] = dist[frm] + cost;
                    isupdate = true;
                }
            }
            if(not isupdate){
                distance = dist;
                is_negative_loop = false;
                break;
            }
 
            if(i == n-1 && isupdate){
                is_negative_loop = true;
            }
        }
                 
    }
 
};

vector<vector<int>> warshall_floyd(vector<vector<int>> edges,int v){
    vector<vector<int>> ret = edges;
    rep(k,0,v){
        rep(i,0,v){
            rep(j,0,v){
                if(ret[i][k] == inf || ret[k][j] == inf) continue;
                ret[i][j] = min(ret[i][j],ret[i][k] + ret[k][j]);
            }
        }
    }
    return ret;
 
}


struct binomial_coefficient{
    vector<int> facts;
    vector<int> invs;

    int mod_pow(int x, int n, int m){if(n== 0) return 1;int res = mod_pow(x*x%m,n/2,m);if(n&1) res = res*x%m;return res;}
    int inv(int n){return mod_pow(n,mod-2,mod);}

    binomial_coefficient(int n){
        facts.push_back(1); invs.push_back(1);
        for(int i = 1; i <= n; i++){
            facts.push_back(facts[i-1]*i%mod);
            invs.push_back(inv(facts[i]));
        }
        
    }

    int nPr(int n, int r){
        if(r > n) return 0;
        return (facts[n]%mod * invs[n-r]% mod)%mod;
    }

    int nCr(int n, int r){
        if(r > n) return 0;
        return facts[n]%mod * invs[n-r]%mod * invs[r] % mod;
    }

    int nHr(int n, int r){
        if(n==0 && r==0) return 1;
        return nCr(n+r-1, r);
    }

};



bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } 

    if(n%2 == 0) return false;
    if(n%3 == 0) return false;
 

    if(n%6 != 1 && n%6 != 5) return false;



    for(unsigned i=5;i*i<=n;i+=6){
        if(n%i     == 0) return false; // 6n-1
        if(n%(i+2) == 0) return false; // 6n+1
    }

    return true;
}



vector<int> eratothenes(int n){

    vector<int> ret;

    vector<bool> isprime(n + 1, true);

    for(int i = 2; i < sqrt(n + 1) + 1; i++){
        if(isprime[i]){
            for(int j = 2; i * j < n + 1; j++){
                isprime[i * j] = false;
            }
        }
    }


    for(int i = 2; i < n + 1; i++){
        if(isprime[i]) ret.push_back(i);
    }

    return ret;

}

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}



struct cumsum1d{
    int n;
    vector<int> arr;

    cumsum1d(int len){
        n = len;
        rep(i,0,n) arr.push_back(0);
    }

    void init(vector<int> vec){
        arr = vec;
        n = arr.size();
    }

    void add(int a, int b, int val = 1){
        arr[a] += val;
        if(b + 1 < n) arr[b + 1] -= val;
    }

    void build(){
        rep(i,1,n) arr[i] += arr[i-1];
    }

    int query(int from, int to){
        int ret = arr[to];
        if(from) ret -= arr[from - 1];
        return ret;
    }

};


struct cumsum2d{
    int x;
    int y;
    vector<vector<int>> arr;

    cumsum2d(int width, int height){
        x = width;
        y = height;
        arr = vector<vector<int>>(x, vector<int>(y, 0));
    }

    void init(vector<vector<int>> vec){
        arr = vec;
        x = arr[0].size();
        y = arr.size();
        
    }

    void add(int x1, int y1, int x2, int y2, int val = 1){
        arr[y1][x1] += val;
        if(x2 + 1 < x) arr[y1][x2 + 1] -= val;
        if(y2 + 1 < y) arr[y2 + 1][x1] -= val;
        if(x2 + 1 < x && y2 + 1 < y) arr[y2 + 1][x2 + 1] += val; 
    }

    void build(){
        for(int i = 0; i < y; i++){
            for(int j = 1; j < x; j++){
                arr[i][j] += arr[i][j - 1];
            }
        }
        for(int i = 1; i < y; i++){
            for(int j = 0; j < x; j++){
                arr[i][j] += arr[i - 1][j];
            }
        }
    }

    int query(int x1, int y1, int x2, int y2){
        int ret = arr[y2][x2];
        if(-1 < x1 - 1) ret -= arr[y2][x1 - 1];
        if(-1 < y1 - 1) ret -= arr[y1 - 1][x2];
        if(-1 < x1 - 1 && -1 < y1 - 1) ret += arr[y1 - 1][x1 - 1];
        return ret;
    }

};





    




    






