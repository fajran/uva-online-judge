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

#define DEBUG

#if defined(ONLINE_JUDGE) || !defined(DEBUG)
#define D(...)
#else
#define D printf
#endif

using namespace std;

int main() {
  long tc;
  cin >> tc;
  while (tc--) {
    long nn;
    cin >> nn;
    long t[nn];

    long s = 0;
    for (long i=0; i<nn; i++) {
      long v;
      cin >> v;
      t[i] = v;
      for (long j=0; j<i; j++) {
        if (t[j] <= v) s++;
      }
    }

    printf("%ld\n", s);
  }
}

// vim: ts=2 sts=2

