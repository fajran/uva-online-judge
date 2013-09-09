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

int main() {
  int T[] = {
    1,2,3, 1,2,3,
    1,2,3, 1,2,3, 1,2,3,
    1,2,3,4, 1,2,3, 1,2,3,4
  };

  string line;
  getline(cin, line);
  int TC = atoi(line.c_str());
  for (int tc=0; tc<TC; tc++) {
    getline(cin, line);
    const char* str = line.c_str();
    int len = line.length();

    int cnt = 0;
    for (int i=0; i<len; i++) {
      char ch = str[i];
      if (ch == ' ') cnt += 1;
      else cnt += T[ch-'a'];
    }

    printf("Case #%d: %d\n", tc+1, cnt);
  }
}

// vim: ts=2 sts=2

