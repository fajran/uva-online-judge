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

inline double r(double dx, double dy) {
  return sqrt(dx*dx + dy*dy);
}

int main() {
  while (true) {
    int n;
    double a;
    scanf("%d %lf", &n, &a);
    if (n == 0) break;

    D("> %d %lf\n", n, a);

    int m = 0;
    for (int i=0; i<n; i++) {
      double x, y;
      scanf("%lf %lf", &x, &y);
      D("-> %lf %lf\n", x, y);
      D("   %lf %lf %lf %lf\n", r(x, y), r(x,a-y), r(a-x,y), r(a-x,a-y));

      if (r(x, y) <= a &&
          r(x, a-y) <= a &&
          r(a-x, y) <= a &&
          r(a-x, a-y) <= a) m++;
      D(">> m=%d\n", m);
    }

    D("n=%d m=%d\n", n, m);
    double aa = m * a * a / n;
    printf("%.05lf\n", aa);
  }
}

// vim: ts=2 sts=2

