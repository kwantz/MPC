#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int arr[n][n] = {};
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  int row[n] = {};
  int col[n] = {};
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      row[i] += arr[i][j];
      col[j] += arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    printf("Row[%d] = %d\n", i, row[i]);
  }
  printf("\n");

  for (int i = 0; i < n; i++) {
    printf("Col[%d] = %d\n", i, col[i]);
  }
  printf("\n");
}
