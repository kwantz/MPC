#include <bits/stdc++.h>

using namespace std;

bool desc(int a, int b) {
  if (a > b) return true;
  return false;
}

int main() {
  // Array
  int arr[] = {9, 6, 59, 14, 45, 63};

  sort(arr, arr+6);

  for (int i = 0; i < 6; i++) {
    printf("%d\n", arr[i]);
  }

  // Vector
  vector<int> vec;

  vec.push_back(9);
  vec.push_back(6);
  vec.push_back(59);
  vec.push_back(14);
  vec.push_back(45);
  vec.push_back(63);

  sort(vec.begin(), vec.end());

  for (int i = 0; i < 6; i++) {
    printf(" %d\n", arr[i]);
  }

  // Sorting desc

  // Cara #1
  reverse(vec.begin(), vec.end()); // sort terlebih dahulu

  // Cara #2
  sort(vec.begin(), vec.end(), desc); // gunakan compare desc
}
