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

const int MM = 100;

int main() {
  int len[MM];
  bzero(len, sizeof(len));

  char t[MM][MM];
  memset(t, ' ', sizeof(t));

  int w[MM];
  bzero(w, sizeof(w));

  string line;
  int n = 0;
  int m = 0;
  while (true) {
    getline(cin, line);
    if (feof(stdin)) break;

    len[n] = line.length();
    if (m < len[n]) m = len[n];
    const char* str = line.c_str();

    for (int i=0, l=len[n]; i<l; i++) {
      char ch = str[i];
      t[n][i] = ch;
      // w[i] = n+1;
      // if (ch != ' ' && w[i] == 0) w[i] = n+1;
      if (w[i] == 0) w[i] = n+1;
    }

    n++;
  }

  for (int i=0; i<m; i++) {
    //int x = w[i];
    if (w[i] > 0)
      w[i] = n - w[i] + 1;
    //printf("(w%2d->%d) ", x, w[i]);
  }
  //printf("\n");

  for (int i=0; i<m; i++) {
    //printf("(%2d->%2d) ", i, w[i]);
    for (int j=0, k=n-1; j<w[i]; j++, k--) {
      printf("%c", t[k][i]);
    }
    printf("\n");
  }
}

// vim: ts=2 sts=2

