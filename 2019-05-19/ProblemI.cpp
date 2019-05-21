/*
Algorithm Generating Palindrome with DP
*/

#include <bits/stdc++.h>

using namespace std;

int memo[1005][1005];
char s[1005];

bool isPalindrome(int l, int r) {
  if (l == r) return true;
  if (l+1 == r) return s[l] == s[r];
  if (memo[l][r] != -1) return memo[l][r];

  bool ans = false;
  if (s[l] == s[r]) ans = isPalindrome(l+1, r-1);
  return memo[l][r] = ans;
}

set<string> countPalindrome() {
  int i, j, n;
  set<string> ans;

  memset(memo, -1, sizeof memo);
  n = strlen(s);

  for (int i=0; i<n; i++) {
    string temp = "";
    temp += s[i];
    for (int j=i+1; j<n; j++) {
      temp += s[j];
      if (isPalindrome(i, j))
        ans.insert(temp);
    }
  }

  return ans;
}

int main() {
  while (scanf("%s", &s) != EOF) {
    set<string> results = countPalindrome();
    for (auto &result : results)
      printf("%s\n", result.c_str());
    printf("\n");
  }
}
