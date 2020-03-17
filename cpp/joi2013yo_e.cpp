#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAX_N = 60;
 
int n, k;
 
int X1[60], Y1[60], Z1[60];
int X2[60], Y2[60], Z2[60];
 
vector<ll> x, y, z;
 
int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> X1[i] >> Y1[i] >> Z1[i] >> X2[i] >> Y2[i] >> Z2[i];
    x.push_back(X1[i]);
    x.push_back(X2[i]);
    y.push_back(Y1[i]);
    y.push_back(Y2[i]);
    z.push_back(Z1[i]);
    z.push_back(Z2[i]);
  }
 
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(z.begin(), z.end());
 
  ll ans = 0;
  for (int X = 0; X < x.size() - 1; X++){
    for (int Y = 0; Y < y.size() - 1; Y++){
      for (int Z = 0; Z < z.size() - 1; Z++){
        int cnt = 0;
        for (int i = 0; i < n; i++){
          if (X1[i] <= x[X] && x[X + 1] <= X2[i] &&
              Y1[i] <= y[Y] && y[Y + 1] <= Y2[i] &&
              Z1[i] <= z[Z] && z[Z + 1] <= Z2[i]) cnt++;
        }
 
        if (cnt >= k){
          ans += (x[X + 1] - x[X]) * (y[Y + 1] - y[Y]) * (z[Z + 1] - z[Z]);
        }
      }
    }
  }
 
  cout << ans << endl;
}
