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
#define D printf
#endif

using namespace std;

int main() {
  while (true) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;

    int prev;
    int score;
    scanf("%d", &prev);
    score = prev;

    int val;
    for (int i=1; i<n; i++) {
      scanf("%d", &val);
      if (prev + val > val) prev = prev + val;
      else prev = val;
      if (prev > score) score = prev;
    }

    if (score <= 0) printf("Losing streak.\n");
    else printf("The maximum winning streak is %d.\n", score);
  }
}

// vim: ts=2 sts=2

