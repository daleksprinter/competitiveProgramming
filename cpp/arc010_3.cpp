#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int n, m, combo, allColor, color[100], dp[5001][13][1025], bit; // num previousColor,usedColor
string s;
bool vis[5001][13][1025];
int colorNum[30];

int DP(int num, int previousColor, int usedColor) {
  if (num == n) {
    if ((1 << m) - 1 == usedColor)
      return allColor;
    return 0;
  }

  if (vis[num][colorNum[previousColor]][usedColor])
    return dp[num][colorNum[previousColor]][usedColor];
  vis[num][colorNum[previousColor]][usedColor] = 1;

  int maximum = DP(num + 1, previousColor, usedColor), cnt = color[s[num]]; // color bonus
  // use this color
  if (s[num] == previousColor)
    cnt += combo;
  maximum = max(DP(num + 1, s[num], usedColor | (1 << colorNum[s[num]])) + cnt, maximum);

  return dp[num][colorNum[previousColor]][usedColor] = maximum;
}

int main() {
  cin >> n >> m >> combo >> allColor;
  REP(i, m) {
    char c;
    int p;
    cin >> c >> p;
    color[c] = p;
    colorNum[c] = i;
  }
  cin >> s;
  cout << DP(0, -1, 0) << endl;
}

