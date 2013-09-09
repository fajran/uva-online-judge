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
#define D(s, ...) fprintf(stderr, s, ##__VA_ARGS__)
#endif

using namespace std;

const int MM = 51;

int main() {
  char cc[MM];
  while (true) {
    scanf("%s", cc);
    if (cc[0] == '#') break;

    int len = strlen(cc);
    if (next_permutation(cc, cc+len)) {
      printf("%s\n", cc);
    }
    else {
      printf("No Successor\n");
    }
  }
}

// vim: ts=2 sts=2

