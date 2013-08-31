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
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n;
    scanf("%d", &n);
    int vmin = INT_MAX;
    int vmax = INT_MIN;
    for (int i=0; i<n; i++) {
      int val;
      scanf("%d", &val);
      if (val < vmin) vmin = val;
      if (val > vmax) vmax = val;
    }

    printf("%d\n", 2*(vmax-vmin));
  }
}

// vim: ts=2 sts=2

