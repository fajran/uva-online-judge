#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <queue>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#if defined(ONLINE_JUDGE) || !defined(DEBUG)
#define D(...)
#else
#define D(s, ...) fprintf(stderr, s, ##__VA_ARGS__)
#endif

using namespace std;

const int ML = 12 + 1;
const int MP = 10;

int main() {
  int tc = 0;
  while (true) {
    int N;
    cin >> N;
    if (feof(stdin)) break;

    vector<string> names(N);
    map<string, int> idx;
    int net[N];

    for (int i=0; i<N; i++) {
      cin >> names[i];
      idx[names[i]] = i;
      net[i] = 0;
    }

    for (int i=0; i<N; i++) {
      string src, dst;
      cin >> src;
      int sid = idx[src];

      int m, n;
      cin >> m >> n;
      if (n == 0) continue;

      int d = m / n;
      for (int j=0; j<n; j++) {
        cin >> dst;
        int id = idx[dst];
        net[id] += d;
        net[sid] -= d;
      }
    }

    if (tc > 0) printf("\n");
    tc++;

    for (int i=0; i<N; i++) {
      int id = idx[names[i]];
      cout << names[i] << " " << net[id] << endl;
    }
  }
}

// vim: ts=2 sts=2

