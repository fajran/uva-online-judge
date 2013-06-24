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

using namespace std;

int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long X, Y, a, b;
    cin >> X >> Y;

    bool ok = false;
    if (X >= Y) {
      long long a2 = X + Y;
      if (a2 % 2 == 0) {
        ok = true;
        a = a2 / 2;
        b = a - Y;
        if (b > a) {
          long long tmp = a;
          a = b;
          b = tmp;
        }
      }
    }

    if (!ok) printf("impossible\n");
    else printf("%lld %lld\n", a, b);
  }
}

// vim: ts=2 sts=2

