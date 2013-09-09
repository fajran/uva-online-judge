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

const int MM = 1000000 + 1;

int main() {
  char S[MM];
  int tc = 0;
  while (true) {
    scanf("%s", S);
    if (feof(stdin) || strlen(S) == 0) break;
    tc++;
    printf("Case %d:\n", tc);

    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
      int I, J;
      scanf("%d %d", &I, &J);
      if (I > J) {
        int tmp = I;
        I = J;
        J = tmp;
      }

      char c = S[I];
      bool ok = true;
      for (int j=I; j<=J && ok; j++) {
        if (S[j] != c) ok = false;
      }

      if (ok) printf("Yes\n");
      else printf("No\n");
    }
  }
}

// vim: ts=2 sts=2

