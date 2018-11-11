#include "bits/stdc++.h"
using namespace std;


/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int short int 
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
const int mod = 1000000007;
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
string s;
vi dist;
int lastx, lasty;

bool dpx[8003][16010];
bool dpy[8003][16010];


void dfsx(int i, int p){
    
    dpx[i][p + 8005] = true;

    if(i + 2 < dist.size()){
        if(!dpx[i + 2][p + dist[i + 2] + 8005]) dfsx(i + 2, p + dist[i + 2]);
        if(!dpx[i + 2][p - dist[i + 2] + 8005]) dfsx(i + 2, p - dist[i + 2]);
    }

}

void dfsy(int i, int p){
    
    if(i != -1) dpy[i][p + 8005] = true;

    if(i + 2 < dist.size()){
        if(!dpy[i + 2][p + dist[i + 2] + 8005]) dfsy(i + 2, p + dist[i + 2]);
        if(!dpy[i + 2][p - dist[i + 2] + 8005]) dfsy(i + 2, p - dist[i + 2]);
    }
}

signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);


    int x, y;
    cin >> s >> x >> y;




    int i = 0;
    while(i < s.size()){
        int cnt = 0;
        while(i < s.size() && s[i] == 'F'){
            cnt++;
            i++;
        }
    
        dist.push_back(cnt);

        i++;
    }

    if(dist.size() == 1){
        if(dist[0] == x && y == 0){
            print("Yes");
        }else{
            print("No");
        }
        return 0;
    }

    memset(dpx, 0, sizeof(dpx));
    memset(dpy, 0, sizeof(dpy));
    

    dfsx(0, dist[0]);
    dfsy(-1, 0);

    int lx, ly;
    if(dist.size() % 2 == 0){
        lx = dist.size() - 2;
        ly = dist.size() - 1;
    }else{
        lx = dist.size() - 1;
        ly = dist.size() - 2;
    }
    
    if(dpx[lx][x + 8005] && dpy[ly][y + 8005]){
        print("Yes");
    }else{
        print("No");
    }







    









    











   








    
    












    

    








    






    


    
    

    
    






    




    

    





    

   




    

    

    



    
    



    







    

    

    




    



    



    

 
    
    


    

    
   
    













}






    










    




    









