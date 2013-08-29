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
    double h, u, d, f;
    int hh;
    cin >> hh >> u >> d >> f;
    if (hh == 0) break;
    h = hh;

    double up = u;
    double dec = up * f / 100.0;
    double curr = 0;

    int day = 0;
    while (true) {
      day++;
      if (up > 0) {
        curr += up;
      }
      if (curr > h) break;
      curr -= d;
      if (curr < 0) break;
      up = up - dec;
    }


    if (curr > h) printf("success on day %d\n", day);
    else printf("failure on day %d\n", day);
  }
}

// vim: ts=2 sts=2

