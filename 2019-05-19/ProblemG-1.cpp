/*
Without Bignum
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> factorials;
void generate() {
  factorials.push_back(1);
  factorials.push_back(1);
  for (ll i = 2; i<=10; i++)
    factorials.push_back(factorials[i-1] * i);
}

void ithPermutation (int n, ll i) {
  vector<ll> permutations;

  for (int j=0; j<n; j++) {
    if (i < factorials[n-j-1]) permutations.push_back(0);
    else permutations.push_back(i / factorials[n-j-1]);
    i %= factorials[n-j-1];
  }

  for (int j=n-1; j>0; j--)
    for (int k=j-1; k>=0; k--)
      if (permutations[j] >= permutations[k])
        permutations[j]++;

  for (int j=0; j<n; j++) {
    if (j > 0) printf(" ");
    printf("%I64d", permutations[j] + 1);
  }

  printf("\n");
}

int main() {

  int n;
  ll i;
  generate();

  while (scanf("%d", &n) != EOF) {
    scanf("%I64d", &i);
    ithPermutation(n, i);
  }
}
