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
  int a, b;
  while (true) {
    cin >> a >> b;
    if (a == 0 && b == 0) break;

    int n = (int)sqrt(a);
    int cnt = 0;

    while (n*n <= b) {
      if (n*n >= a) cnt++;
      n++;
    }

    printf("%d\n", cnt);
  }
}

// vim: ts=2 sts=2

