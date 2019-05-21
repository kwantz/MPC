#include <bits/stdc++.h>

using namespace std;

int main() {
  int M, P, L, E, R, S, N;
  while (scanf("%d %d %d %d %d %d %d", &M, &P, &L, &E, &R, &S, &N) != EOF) {
    for (int i=0; i<N; i++) {
      int egg = M * E;
      M = P / S;
      P = L / R;
      L = egg;
    }
    printf("%d\n", M);
  }
}
