#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 6;
  int input[] = {3, 2, 5, 2, 2, 3};
  int output[] = {0, 0, 0, 0, 0, 0};

  int mini = INT_MAX;
  int maxi = -INT_MAX;

  for (int i = 0; i < n; i++) {
    if (input[i] < mini) mini = input[i];
    if (input[i] > maxi) maxi = input[i];
  }

  int len = maxi - mini + 1;

  // Prepare a frequency array input with
  // size maxi - mini + 1, initialize with zeros.
  int arr[len] = {};

  // Pass through array input and update
  // the frequency arr[input[i] - mini]++.
  for (int i = 0; i < n; i++) {
    int idx = input[i] - mini;
    arr[idx]++;
  }

  // Compute Prefix Sums
  int sumi[len] = {};
  for (int i = 0; i < len; i++) {
    if (i == 0) sumi[i] = arr[i];
    else sumi[i] = sumi[i-1] + arr[i];
  }

  // Go backwards, place input[i] to output at index sumi[input[i] - mini]
  // as it the location, then decrement sumi[input[i] - mini]
  for (int i = 0; i < n; i++) {
    int idx_sumi = input[i] - mini;
    int idx_output = sumi[idx_sumi] - 1;

    output[idx_output] = input[i];
    sumi[idx_sumi]--;
  }

  for (int i = 0; i < 6; i++) {
    printf("%d\n", output[i]);
  }
}
