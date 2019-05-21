/*
Algorithm KMP Algorithm

Source: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPSArray(char pat[], int M) {
  vector<int> lps;
  lps.resize(M);

  lps[0] = 0;

  int len = 0, i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      lps[i++] = ++len;
    }
    else {
      if (len != 0) len = lps[len - 1];
      else lps[i++] = 0;
    }
  }
  return lps;
}

  /* Illustration of preprocessing (or construction of lps[])
pat[] = "AAACAAAA"

len = 0, i  = 0.
lps[0] is always 0, we move
to i = 1

len = 0, i  = 1.
Since pat[len] and pat[i] match, do len++,
store it in lps[i] and do i++.
len = 1, lps[1] = 1, i = 2

len = 1, i  = 2.
Since pat[len] and pat[i] match, do len++,
store it in lps[i] and do i++.
len = 2, lps[2] = 2, i = 3

len = 2, i  = 3.
Since pat[len] and pat[i] do not match, and len > 0,
set len = lps[len-1] = lps[1] = 1

len = 1, i  = 3.
Since pat[len] and pat[i] do not match and len > 0,
len = lps[len-1] = lps[0] = 0

len = 0, i  = 3.
Since pat[len] and pat[i] do not match and len = 0,
Set lps[3] = 0 and i = 4.
We know that characters pat
len = 0, i  = 4.
Since pat[len] and pat[i] match, do len++,
store it in lps[i] and do i++.
len = 1, lps[4] = 1, i = 5

len = 1, i  = 5.
Since pat[len] and pat[i] match, do len++,
store it in lps[i] and do i++.
len = 2, lps[5] = 2, i = 6

len = 2, i  = 6.
Since pat[len] and pat[i] match, do len++,
store it in lps[i] and do i++.
len = 3, lps[6] = 3, i = 7

len = 3, i  = 7.
Since pat[len] and pat[i] do not match and len > 0,
set len = lps[len-1] = lps[2] = 2

len = 2, i  = 7.
Since pat[len] and pat[i] match, do len++,
store it in lps[i] and do i++.
len = 3, lps[7] = 3, i = 8

We stop here as we have constructed the whole lps[].
*/

vector<int> KMPSearch(char txt[], char pat[]) {
  int N = strlen(txt);
  int M = strlen(pat);

  int i = 0, j = 0;
  vector<int> result;
  vector<int> lps = computeLPSArray(pat, M);

  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == M) {
      result.push_back(i - j);
      j = lps[j - 1];
    }
    else if (i < N && pat[j] != txt[i]) {
      if (j != 0) j = lps[j - 1];
      else i = i + 1;
    }
  }

  return result;
}

/* Illustration of KMP Search
txt[] = "AAAAABAAABA"
pat[] = "AAAA"
lps[] = {0, 1, 2, 3}

i = 0, j = 0
txt[] = "AAAAABAAABA"
pat[] = "AAAA"
txt[i] and pat[j] match, do i++, j++

i = 1, j = 1
txt[] = "AAAAABAAABA"
pat[] = "AAAA"
txt[i] and pat[j] match, do i++, j++

i = 2, j = 2
txt[] = "AAAAABAAABA"
pat[] = "AAAA"
pat[i] and pat[j] match, do i++, j++

i = 3, j = 3
txt[] = "AAAAABAAABA"
pat[] = "AAAA"
txt[i] and pat[j] match, do i++, j++

i = 4, j = 4
Since j == M, print pattern found and reset j,
j = lps[j-1] = lps[3] = 3

Here unlike Naive algorithm, we do not match first three
characters of this window. Value of lps[j-1] (in above
step) gave us index of next character to match.
i = 4, j = 3
txt[] = "AAAAABAAABA"
pat[] =  "AAAA"
txt[i] and pat[j] match, do i++, j++

i = 5, j = 4
Since j == M, print pattern found and reset j,
j = lps[j-1] = lps[3] = 3

Again unlike Naive algorithm, we do not match first three
characters of this window. Value of lps[j-1] (in above
step) gave us index of next character to match.
i = 5, j = 3
txt[] = "AAAAABAAABA"
pat[] =   "AAAA"
txt[i] and pat[j] do NOT match and j > 0, change only j
j = lps[j-1] = lps[2] = 2

i = 5, j = 2
txt[] = "AAAAABAAABA"
pat[] =    "AAAA"
txt[i] and pat[j] do NOT match and j > 0, change only j
j = lps[j-1] = lps[1] = 1

i = 5, j = 1
txt[] = "AAAAABAAABA"
pat[] =     "AAAA"
txt[i] and pat[j] do NOT match and j > 0, change only j
j = lps[j-1] = lps[0] = 0

i = 5, j = 0
txt[] = "AAAAABAAABA"
pat[] =      "AAAA"
txt[i] and pat[j] do NOT match and j is 0, we do i++.

i = 6, j = 0
txt[] = "AAAAABAAABA"
pat[] =       "AAAA"
txt[i] and pat[j] match, do i++ and j++

i = 7, j = 1
txt[] = "AAAAABAAABA"
pat[] =       "AAAA"
txt[i] and pat[j] match, do i++ and j++

We continue this way...
*/

char txt[1000000005], pat[1000000005];

int main() {
  while (scanf("%[^\n]s", &pat) != EOF) {
    getchar();
    scanf("%[^\n]s", &txt);
    getchar();

    vector<int> results = KMPSearch(txt, pat);
    for (int i=0; i<results.size(); i++) {
      if (i > 0) printf(" ");
      printf("%d", results[i]);
    }

    printf("\n");
  }
  return 0;
}
