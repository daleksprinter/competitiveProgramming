//#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
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
const string alpha = "abcdefghijklmnopqrstuvwxyz";

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
void print(double n){cout << n << endl;}

//main------------------------------------------------------------------------------------------



int digitsum(int n){
    int s = 0;
    while(n > 0){
        s += n%10;
        n/= 10;
    }
    return s;
}

int factorial(int x){
    int res = 1;
    rep(i,2,x+1){
        res *= i;
        res %= mod;
    }
    return res;
}

vector<vector<int> > comb;

void combination(int n, int k, int rest){

}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n = input();

    int ans = 0;
    rep(i,1,10){
        ans += (n / (int)pow(10LL, i)) * (int)pow(10LL, i-1);
        int rest = n % (int)pow(10LL,i);
        rest++;
        int t = min(rest, (int)pow(10LL,i-1) * 2) - (int)pow(10LL, i-1);
        ans += t > -1 ? t : 0;
    }

    print(ans);











}   
