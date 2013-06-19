#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DEBUG

#if defined(ONLINE_JUDGE) || !defined(DEBUG)
#define D(...)
#else
#define D printf
#endif

using namespace std;

int main() {
  string line;
  while (true) {
    getline(cin, line);
    int h, m;
    sscanf(line.c_str(), "%d:%d", &h, &m);
    if (h == 0 && m == 0) break;

    double dm = m / 60.0 * 360.0;
    double dh = h / 12.0 * 360.0 + m / 60.0 * 30.0;
    double d = dm - dh;
    if (d < 0) d = -d;

    double od = 360.0 - d;
    if (od < d) d = od;

    printf("%.3f\n", d);
  }
}

// vim: ts=2 sts=2

