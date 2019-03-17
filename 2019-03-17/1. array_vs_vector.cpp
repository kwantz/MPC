#include <bits/stdc++.h>

using namespace std;

int main() {

  // inisialisasi
  int arr[10];
  vector<int> vec;

  // pemasukan data
  for (int i = 0; i < 10; i++) {
    arr[i] = i + 1;
  }

  for (int i = 0; i < 10; i++) {
    vec.push_back(i + 1);
  }

  // cetak data
  for (int i = 0; i < 20; i++) {
    printf("%d\n", arr[i]);
  }

  for (int i = 0; i < 20; i++) {
    printf("%d\n", vec[i]);
  }
}
