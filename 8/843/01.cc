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

int main() {
  map<string, int> F;
  int N;
  string S;
  while (true) {
    cin >> N >> S;
    if (feof(stdin)) break;

    int len = S.length();
    int max = 0;
    D("%s >> [%s]\n", N, S.c_str());

    string ans = "";
    for (int i=0; i<len-N; i++) {
      string sub = S.substr(i, N);
      if (F.find(sub) == F.end())
        F[sub] = 1;
      else
        F[sub] += 1;
      if (F[sub] > max) {
        max = F[sub];
        ans = sub;
      }
    }

    printf("%s\n", ans.c_str());

  }
}

// vim: ts=2 sts=2

