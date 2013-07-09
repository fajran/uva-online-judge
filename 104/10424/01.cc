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

int go(const char *s, int len) {
  int sum = 0;
  for (int i=0; i<len; i++) {
    char ch = s[i];
    if (ch >= 'A' && ch <= 'Z') sum += (ch - 'A' + 1);
    else if (ch >= 'a' && ch <= 'z') sum += (ch - 'a' + 1);
  }

  while (sum > 9) {
    // printf("-> %d\n", sum);
    sum = (sum / 10) + (sum % 10);
  }
  // printf("  -> %d\n", sum);

  return sum;
}

int main() {
  string a, b;
  while (true) {
    getline(cin, a);
    getline(cin, b);
    if (feof(stdin)) break;

    const char *aa = a.c_str();
    const char *bb = b.c_str();
    int na = a.length();
    int nb = b.length();

    int sa = go(aa, na);
    int sb = go(bb, nb);

    if (sa > sb) {
      int tmp = sa;
      sa = sb;
      sb = tmp;
    }
    // printf("%d vs %d => %.02f %%\n", sa, sb, (double)sa/(double)sb*100.0);
    printf("%.02f %%\n", 100.0*(double)sa/(double)sb);
  }
}

// vim: ts=2 sts=2

