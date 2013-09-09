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

const int MM = 10 + 1;

int main() {
  char line[MM];
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%s", line);
    int len = strlen(line);
    sort(line, line+len);

    do {
      printf("%s\n", line);
    } while (next_permutation(line, line+len));

    printf("\n"); // A blank line should follow each output set.
  }
}

// vim: ts=2 sts=2

