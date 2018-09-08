#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const ll inf = 100100100100100;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<ll> dijkstra(int s, vector< vector<pair<int,ll>>> l, int v){
    vector<ll> dist; rep(i,0,v) dist.push_back(inf); dist[s] = 0;
    priority_queue< pair<int, ll>,vector<pair<int, ll>>,greater<pair<int, ll>>> que; que.push(make_pair(0,s));

    while(!que.empty()){
        pair<int,ll> p = que.top(); que.pop();
        int vertex = p.second;
        if(dist[vertex] < p.first) continue;
        rep(i,0,l[vertex].size()){
            pair<int,ll> to = l[vertex][i];
            if(dist[to.second] > dist[vertex] + to.first){
                dist[to.second] = dist[vertex] + to.first;
                que.push(make_pair(dist[to.second],to.second));
            }
        }
    
    }
    return dist;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
   int n,m,s,t;
   cin >> n >> m >> s >> t;
   s--; t--;

   vector< vector< pair<int,ll> > >yen(n);
   vector< vector< pair<int,ll> > >snuuk(n);

   rep(i,0,m){
       int frm,to,a,b;
       cin >> frm >> to >> a >> b;
        frm--; to--;
        yen[frm].push_back(make_pair(a,to));
        yen[to].push_back(make_pair(a,frm));
        snuuk[frm].push_back(make_pair(b,to));
        snuuk[to].push_back(make_pair(b,frm));
   }

   vector<ll> y_cost = dijkstra(s,yen,n);
   vector<ll> s_cost = dijkstra(t,snuuk,n);

   vector<ll> sumcost;
   rep(i,0,n) {
       sumcost.push_back(y_cost[i] + s_cost[i]);
   }
   
   int i = n-2;
   while(i > -1){
       sumcost[i] = min(sumcost[i], sumcost[i+1]);
       i--;
    }
    rep(i,0,n) cout << 1000000000000000 - sumcost[i] << endl;
   
 
}


