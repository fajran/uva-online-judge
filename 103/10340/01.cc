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
  string line;
  while (true) {
    getline(cin, line);
    if (feof(stdin)) break;

    const char *str = line.c_str();
    int len = line.length();

    const char *A = str;
    const char *B;
    int step = 0;
    int len1 = 0;
    int len2 = 0;
    for (int i=0; i<len; i++) {
      char ch = str[i];
      if (ch == ' ' || ch == '\t') {
        if (step == 0) len1 = i;
        step = 1;
      }
      else if (step == 1) {
        B = str+i;
        break;
      }
    }

    len2 = strlen(B);

    bool ok = true;
    if (len1 > len2) ok = false;
    else {
      int p = 0;
      int cnt = 0;
      for (int i=0; i<len1; i++) {
        char c1 = A[i];
        while (p < len2) {
          char c2 = B[p++];
          // printf("~ %d->%c == %d->%c\n", i, c1, p, c2);
          if (c2 == c1) {
            cnt++;
            break;
          }
        }
      }

      ok = cnt == len1;
    }

    if (ok) printf("Yes\n");
    else printf("No\n");
  }
}

// vim: ts=2 sts=2

