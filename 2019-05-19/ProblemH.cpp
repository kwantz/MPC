#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string team[25], temp[25];

  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    char s[20];
    scanf("%s", &s);
    team[i] = temp[i] = s;
  }

  sort(temp, temp + n);

  bool isIncreasing = true;
  bool isDecreasing = true;
  for (int i=0; i<n; i++) {
    int j = n - i - 1;
    if (team[i] != temp[i]) isIncreasing = false;
    if (team[i] != temp[j]) isDecreasing = false;
  }

  if (isIncreasing) printf("INCREASING\n");
  else if (isDecreasing) printf("DECREASING\n");
  else printf("NEITHER\n");
}
