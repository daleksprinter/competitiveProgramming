#include <bits/stdc++.h>
using namespace std;

//macro-----------------------------------------------------------------------------------------
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i=a;i>b;i--)
#define int long long

//constant--------------------------------------------------------------------------------------
const int inf = 100100100100000;
const int mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//general_method--------------------------------------------------------------------------------
vector<int> cs(vector<int> arr){vector<int> ret = arr;rep(i,1,arr.size()){ret[i] += ret[i-1];}return ret;}
int ceil(int a, int b){if(a%b == 0) return a/b;else return a/b + 1;}
int digitlen(int i){int t = i;int count = 0;while(t){count += 1;t /= 10;}return count;}
int gcd(int m, int n){if((0== m)||(0 == n))return 0;while(m != n){if(m > n)m = m - n;else n = n - m;}return m;}
int lcm(int n, int m){return n*m/gcd(n,m);}

//io_method-------------------------------------------------------------------------------------
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
void print(int n){cout << n << endl;}
void print(vector<int> arr){cout << arr[0];rep(i,1,arr.size()) cout << " " << arr[i];cout << endl;}
void print(string s){cout << s << endl;}
void print(pair<int, int> p){cout << p.first << " " << p.second;}
void print(vector<vector<int>> arr){rep(i,0,arr.size()){print(arr[i]);}}

//main------------------------------------------------------------------------------------------
int mod_pow(int x, int n, int m){if(n== 0) return 1;int res = mod_pow(x*x%m,n/2,m);if(n&1) res = res*x%m;return res;}
int factorial(int x){int res = 1;rep(i,2,x+1){res *= i;res %= mod;}return res;}
int inv(int n){return mod_pow(n,mod-2,mod);}

struct binomial_coefficient{
    vector<int> facts;
    vector<int> invs;
    int maxn;

    void init(int n){
        maxn = n;
        facts.push_back(1); invs.push_back(1);
        for(int i = 1; i < maxn; i++){
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
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    binomial_coefficient bc;
    bc.init(200005);

    int n,m; cin >> n >> m;

    int t = m;
    int ans = 1;

    int cnt = 0;
    while(t % 2 == 0){
        cnt++;
        t /= 2;
    }
    if(cnt > 0) ans = ans * bc.nHr(n, cnt) % mod;

    for(int i = 3; t > 1; i+=2){
        cnt = 0;
        while(t % i == 0){
            cnt++;
            t /= i;
        }
        if(cnt > 0) ans = ans * bc.nHr(n, cnt) % mod;
    }
    print(ans % mod);

}
