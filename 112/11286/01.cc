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
typedef long long LL;

int main() {
  while (true) {
    int S;
    scanf("%d", &S);
    if (S == 0) break;

    map<LL, int> cnt;
    LL clist[5];
    LL h;
    int mx = INT_MIN;
    for (int i=0; i<S; i++) {
      scanf("%lld %lld %lld %lld %lld",
            &clist[0], &clist[1], &clist[2],
            &clist[3], &clist[4]);
      sort(clist, clist+5);
      h = ((((clist[0] * 1000 + clist[1]) * 1000 + clist[2]) * 1000) + clist[3]) * 1000 + clist[4];

      D("h: %lld\n", h);
      if (cnt.find(h) == cnt.end()) cnt[h] = 1;
      else cnt[h]++;

      if (cnt[h] > mx) mx = cnt[h];
    }

    map<LL, int>::iterator ii = cnt.begin();
    int cc = 0;
    for (; ii != cnt.end(); ii++) {
      if (ii->second == mx) cc += ii->second;
    }

    printf("%d\n", cc);
  }
}

// vim: ts=2 sts=2

