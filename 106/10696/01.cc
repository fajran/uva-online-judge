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

int cache[100];

int f91(int num) {
  if (num <= 0 && cache[num] >= 0)
    return cache[num];

  if (num >= 101)
    return num - 10;

  cache[num] = f91(f91(num+11));
  return cache[num];
}

int go(int num) {
  return f91(num);
}

int main() {
  for (int i=0; i<100; i++)
    cache[i] = -1;

  while (true) {
    int num;
    cin >> num;
    if (num == 0) break;
    int res = go(num);
    printf("f91(%d) = %d\n", num, res);
  }
}

// vim: ts=2 sts=2

