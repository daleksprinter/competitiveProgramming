#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  using namespace std;

  int n;
  scanf("%d", &n);

  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }

  int watering_times = 0;
  for (int i = 0; i < n; i++) {
    while(h[i]) {
      watering_times++;
      h[i]--;
      int j = i+1;
      if(j == n) continue;
      while(h[j]) {
        h[j]--;
        j++;
        if(j == n) break;
      }
    }
  }

  cout << watering_times << endl;

  return 0;
}

