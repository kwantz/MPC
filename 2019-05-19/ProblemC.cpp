#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, tc = 1;
  while (scanf("%d", &n) != EOF) {
    int maxi = -1000000005;
    int mini = 1000000005;

    for (int i=0; i<n; i++) {
      scanf("%d", &a);
      if (maxi < a) maxi = a;
      if (mini > a) mini = a;
    }

    printf("Case %d: %d %d %d\n", tc++, mini, maxi, maxi - mini);
  }
}
