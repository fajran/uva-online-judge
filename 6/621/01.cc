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

const int MM = 101;
char line[MM];

enum STAT {
  U, POS, NEG, FAIL, NA
};

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%s", line);
    int len = strlen(line);

    int stat = U;
    if (len == 1 && (line[0] == '1' || line[0] == '4')) {
      stat = POS;
    }
    else if (len == 2 && line[0] == '7' && line[1] == '8') {
      stat = POS;
    }
    else if (len >= 2 && line[len-2] == '3' && line[len-1] == '5') {
      stat = NEG;
    }
    else if (len >= 2 && line[0] == '9' && line[len-1] == '4') {
      stat = FAIL;
    }
    else if (len >= 3 && line[0] == '1' && line[1] == '9' && line[2] == '0') {
      stat = NA;
    }

    assert(stat != U);
    switch (stat) {
    case POS:  printf("+\n"); break;
    case NEG:  printf("-\n"); break;
    case FAIL: printf("*\n"); break;
    case NA:   printf("?\n"); break;
    }
  }
}

// vim: ts=2 sts=2

