/*
Algorithm Kruskal's Minimum Spanning Tree

Source:
https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
https://www.geeksforgeeks.org/union-find/

NB:
1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
3. Repeat step#2 until there are (V-1) edges in the spanning tree.
   The step#2 uses Union-Find algorithm to detect cycle. So we recommend to read following post as a prerequisite.
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

map<int,int> parent;

int findset(int i) {
  if (parent[i] == i) return i;
  return parent[i] = findset(parent[i]);
}

int main() {
  int n;
  scanf("%d", &n);

  vector<iii> data;
  for (int i=0; i<n; i++) {
    parent[i] = i;
    for (int j=0; j<n; j++) {
      int w;
      scanf("%d", &w);

      if (j > i)
        data.push_back(make_tuple(w, i, j));
    }
  }

  // NB #1: Sort the edges
  sort(data.begin(), data.end());

  vector<ii> urut;
  for (int i=0; i<data.size(); i++) {
    int w = get<0>(data[i]);
    int x = get<1>(data[i]);
    int y = get<2>(data[i]);

    // NB #2: Check Cycle
    int a = findset(x);
    int b = findset(y);
    if (a != b) {
      parent[a] = b;
      urut.push_back(make_pair(x+1, y+1));
    }

    // NB #3: already (V-1) edges
    if (urut.size() == n-1) break;
  }

  sort(urut.begin(), urut.end());
  for (int i=0; i<urut.size(); i++) {
    cout << urut[i].first << ' ' << urut[i].second << endl;
  }
}
