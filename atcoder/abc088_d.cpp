#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int inf = 1001001000;
const int mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int h,w;
char c[50][50];
int cost[50][50];

int main(){
    cin >> h >> w;
    int count = 0;
    rep(i,0,h){
        rep(j,0,w){
            char t;
            cin >> t;
            c[i][j] = t;
            cost[i][j] = inf;
            if(t == '.')count++;
        }
    }

    queue<pair< pair<int,int>, int> > q;
    q.push(make_pair(make_pair(0,0),0));
    while(!q.empty()){
        pair<pair<int,int>, int> t = q.front();
        pair<int,int> p = t.first;
        int dist = t.second;
        q.pop();

        if(cost[p.first][p.second] == inf){
            cost[p.first][p.second] = dist;
            
            rep(i,0,4){
                int x = p.second + dx[i];
                int y = p.first + dy[i];
                
                if(-1 < x && x < w && -1 < y && y < h && c[y][x] == '.' && cost[y][x] == inf){
                    q.push(make_pair(make_pair(y,x),dist+1));
                }

            }
        }
    }
    if(cost[h-1][w-1] != inf){
        cout << count - cost[h-1][w-1] - 1 << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;

}



