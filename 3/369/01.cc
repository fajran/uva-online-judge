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

#define DEBUG

#if defined(ONLINE_JUDGE) || !defined(DEBUG)
#define D(...)
#else
#define D printf
#endif

using namespace std;

typedef unsigned long long ull;

const int M = 100;

int main() {
  ull n, m;
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    ull nn = n;
    ull mm = m;

    ull r = n - m;
    ull t[r+1][m+1];
    bzero(t, sizeof(t));

    for (int i=0; i<=m; i++)
      t[0][i] = 1;
    for (int i=1; i<=r; i++) {
      t[i][0] = 1;
      for (int j=1; j<=m; j++) {
        t[i][j] = t[i][j-1] + t[i-1][j];
      }
    }

    // for (int i=0; i<=r; i++) {
    //   for (int j=0; j<=m; j++) {
    //     printf("%lld ", t[i][j]);
    //   }
    //   printf("\n");
    // }

    ull c = t[r][m];

    printf("%lld things taken %lld at a time is %lld exactly.\n", nn, mm, c);
  }
}

// vim: ts=2 sts=2

