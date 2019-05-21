#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, n, a, rooms[105] = {};

  scanf("%d %d", &r, &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &a);
    rooms[a] = 1;
  }

  for (int i=1; i<=r; i++) {
    if (rooms[i] == 0) {
      printf("%d\n", i);
      return 0;
    }
  }

  printf("too late\n");
  return 0;
}
