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
    long long n, k;
    cin >> n >> k;
    if (feof(stdin)) break;

    long long cnt = n;
    while (n / k > 0) {
      long long div = n / k;
      long long rem = n - div * k;
      n = div + rem;
      cnt += div;
    }

    printf("%lld\n", cnt);
  }
}

// vim: ts=2 sts=2

