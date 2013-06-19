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

using namespace std;

struct Rectangle {
  double x1;
  double y1;
  double x2;
  double y2;

  void set(double x1, double y1, double x2, double y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
  }

  bool inside(double x, double y) {
    return x1 < x && x < x2 && y1 > y && y > y2;
  }
};

const int N = 10;

Rectangle rr[N];

int main() {
  int n;

  string line;
  while (true) {
    getline(cin, line);
    if (line[0] == '*') break;

    double x1, y1, x2, y2;
    //printf("> %s\n", line.c_str());
    int t = sscanf(line.c_str(), "r %lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    //printf("-> %d\n", t);
    rr[n].set(x1, y1, x2, y2);
    n++;

    //printf("rect %f %f %f %f\n", x1, y1, x2, y2);
  }

  int tc = 0;
  while (true) {
    getline(cin, line);

    double x, y;
    sscanf(line.c_str(), "%lf %lf", &x, &y);
    if (x == 9999.9 && y == 9999.9) break;

    //printf("-> %f %f\n", x, y);

    tc++;
    bool found = false;
    for (int i=0; i<n; i++) {
      if (rr[i].inside(x, y)) {
        printf("Point %d is contained in figure %d\n", tc, i+1);
        found = true;
      }
    }

    if (!found) {
      printf("Point %d is not contained in any figure\n", tc);
    }
  }
}

// vim: ts=2 sts=2

