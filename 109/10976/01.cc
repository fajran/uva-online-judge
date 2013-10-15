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
  while (true) {
    int k;
    scanf("%d", &k);
    if (feof(stdin)) break;

    vector<int> aa;
    vector<int> bb;

    int x = k + 1;
    int limit = -INT_MAX;
    while (true) {
      int xk = x * k;
      int a = xk / k;
      int b = xk / x;
      int r = a - b;
      if (xk % r == 0) {
        xk = xk / r;
        if (limit < xk) limit = xk;

        aa.push_back(xk);
        bb.push_back(x);
      }

      if (x >= xk) break;
      x = x + 1;
    }

    printf("%lu\n", aa.size());
    for (int i=0, _i=aa.size(); i<_i; i++) {
      printf("1/%d = 1/%d + 1/%d\n", k, aa[i], bb[i]);
    }
  }
}

// vim: ts=2 sts=2

