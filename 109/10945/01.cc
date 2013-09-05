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
  while (true) {
    string line;
    getline(cin, line);
    if (line == "DONE") break;

    const char* str = line.c_str();
    bool p = true;
    int len = line.length();
    for (int i=0, j=len-1; i<len && i < j && p; i++, j--) {
      char a = str[i] | 040;
      char b = str[j] | 040;
      while (a < 'a' || a > 'z') {
        a = str[++i] | 040;
      }
      while (b < 'a' || b > 'z') {
        b = str[--j] | 040;
      }
      if (a != b) p = false;
    }

    if (p) printf("You won't be eaten!\n");
    else printf("Uh oh..\n");
  }
}

// vim: ts=2 sts=2

