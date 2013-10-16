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

int get_comb_hash(int a, int b, int c) {
  int m[] = { a, b, c };
  sort(m, m + 3);
  return (m[0] << 16) + (m[1] << 8) + m[2];
}

int main() {
  map<int, int> P;
  map<int, int> C;

  while (true) {
    int n;
    scanf("%d", &n);
    if (n <= 0) break;

    set<int> sperm;
    set<int> scomb;

    int perm = 0;
    int comb = 0;

    if (P.find(n) == P.end()) {
      for (int a=0; a<=21; a++) for (int aa=1; aa<=3; aa++) {
        for (int b=0; b<=21; b++) for (int bb=1; bb<=3; bb++) {
          for (int c=0; c<=21; c++) for (int cc=1; cc<=3; cc++) {
            int sa = a, sb = b, sc = c,
                ma = aa, mb = bb, mc = cc;
            if (sa == 21) { sa = 50; ma = 1; }
            if (sb == 21) { sb = 50; mb = 1; }
            if (sc == 21) { sc = 50; mc = 1; }
            sa = sa * ma;
            sb = sb * mb;
            sc = sc * mc;

            if (sa + sb + sc == n) {

              int h = (sa << 16) + (sb << 8) + sc;
              if (sperm.find(h) == sperm.end()) {
                D("%d x %d + %d x %d + %d x %d = %d\n", aa, a, bb, b, cc, c, n);
                perm++;
                sperm.insert(h);
              }

              h = get_comb_hash(sa, sb, sc);
              if (scomb.find(h) == scomb.end()) {
                comb++;
                scomb.insert(h);
              }
            }
          }
        }
      }

      P[n] = perm;
      C[n] = comb;
    }
    else {
      perm = P[n];
      comb = C[n];
    }

    if (perm == 0) {
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    }
    else {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
    }
    printf("**********************************************************************\n");
  }

  printf("END OF OUTPUT\n");
}

// vim: ts=2 sts=2

