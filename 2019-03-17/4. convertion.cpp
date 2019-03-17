#include <bits/stdc++.h>

using namespace std;

string int_2_str(int n) {
  string results = "";
  while (n > 0) {
    int x = n % 10;
    char c = x + '0';

    n /= 10;
    results = c + results;
  }
  return results;
}

int str_2_int(string n) {
  int result = 0;
  for (int i = 0; i < n.size(); i++) {
    int x = n[i] - '0';
    result = result * 10 + x;
  }
  return result;
}

int main() {
  // INT to STRING
  int n = 123;
  string temp = int_2_str(n);

  temp = "00000" + temp;
  cout << temp << endl;

  // STRING to INT
  string m = "0000000056789";
  cout << str_2_int(m) << endl;

  // Count Digit INT
  int x = 1257;
  int y = log10(x) + 1;
  cout << y << endl;
}
