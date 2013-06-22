#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

void go(long num) {
  long s = (long)sqrt((double)num);
  if (s * s == num)
    printf("yes\n");
  else
    printf("no\n");
}

int main() {
  while (true) {
    long num;
    cin >> num;
    if (num == 0) break;
    go(num);
  }
}

// vim: ts=2 sts=2

