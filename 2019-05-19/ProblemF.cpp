#include <bits/stdc++.h>

using namespace std;

bool check(char input[], int i) {
  return input[i] != input[i+1] && input[i] != input[i+2] && input[i+1] != input[i+2];
}

int main() {
  char input[1000005];
  scanf("%s", &input);

  int len = strlen(input);
  for (int i=0; i<len; i++) {
    if (i <= len-3 && check(input, i)) {
      printf("C");
      i += 2;
    } else {
      if (input[i] == 'R') printf("S");
      if (input[i] == 'B') printf("K");
      if (input[i] == 'L') printf("H");
    }
  }
  printf("\n");
}
