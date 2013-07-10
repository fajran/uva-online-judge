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
  while (true) {
    long n;
    cin >> n;
    if (n == 0) break;

    long a = 0;
    long b = 0;
    bool aa = true;
    long i = 0;
    while (n > 0) {
      if (n % 2 == 1) {
        if (aa) a = a | (1L << i);
        else b = b | (1L << i);
        aa = !aa;
      }
      i++;
      n = n / 2;
    }
    printf("%ld %ld\n", a, b);
  }
}

// vim: ts=2 sts=2

