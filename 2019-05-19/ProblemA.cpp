#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y;
  while (scanf("%d %d", &x, &y)) {
    if (x == 0 && y == 0) break;

    if (x + y == 13) printf("Never speak again.\n");
    else if (y < x) printf("To the convention.\n");
    else if (x < y) printf("Left beehind.\n");
    else printf("Undecided.\n");
  }
}
