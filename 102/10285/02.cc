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
#define D printf
#endif

using namespace std;

const int MM = 102;

char name[1000];
int R, C;
int nums[MM][MM];
int dist[MM][MM];

int start(int i, int j) {
  D("Start: %d %d\n", i, j);
  bzero(dist, sizeof(dist));

  queue<int> qr;
  queue<int> qc;
  queue<int> qd;
  dist[i][j] = 1;
  qr.push(i);
  qc.push(j);

  int mx = INT_MIN;
  while (qr.size() > 0) {
    int i = qr.front();
    int j = qc.front();
    qr.pop();
    qc.pop();

    if (i<1 || j<1 || i>R || j>C) continue;

    int v = nums[i][j];
    int d = dist[i][j];

    if (mx < d) mx = d;

    int u = nums[i-1][j];
    int b = nums[i+1][j];
    int l = nums[i][j-1];
    int r = nums[i][j+1];

#define C(rr, cc) \
    if (dist[rr][cc] < d + 1) { \
      dist[rr][cc] = d + 1; \
      qr.push(rr); \
      qc.push(cc); \
    }
    if (u < v) C(i-1, j);
    if (b < v) C(i+1, j);
    if (l < v) C(i, j-1);
    if (r < v) C(i, j+1);
  }

#ifdef DEBUG
  D("-> dist:\n");
  for (int i=1; i<=R; i++) {
    D("    ");
    for (int j=1; j<=C; j++) {
      printf("%4d ", dist[i][j]);
    }
    printf("\n");
  }
#endif

  return mx;
}

void go() {
  scanf("%s", name);
  scanf("%d %d", &R, &C);
  D("RC %d %d\n", R, C);
  for (int i=0; i<R+2; i++) {
    nums[i][0] = INT_MIN;
    nums[i][C+1] = INT_MIN;
  }
  for (int i=0; i<C+2; i++) {
    nums[0][i] = INT_MIN;
    nums[R+1][i] = INT_MIN;
  }

  for (int i=1; i<=R; i++) {
    for (int j=1; j<=C; j++) {
      scanf("%d", &nums[i][j]);
    }
  }

#ifdef DEBUG
  for (int i=1; i<=R; i++) {
    for (int j=1; j<=C; j++) {
      printf("%4d ", nums[i][j]);
    }
    printf("\n");
  }
#endif

  int mx = INT_MIN;
  for (int i=1; i<=R; i++) {
    for (int j=1; j<=C; j++) {
      int v = nums[i][j];
      int u = nums[i-1][j];
      int b = nums[i+1][j];
      int l = nums[i][j-1];
      int r = nums[i][j+1];
      // in degree == 0
      // D("%d - %d %d %d %d\n", v, u, b, l, r);
      if (v >= u && v >= b && v >= l && v >= r) {
        int dd = start(i, j);
        if (mx < dd) mx = dd;
      }
    }
  }

  printf("%s: %d\n", name, mx);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    go();
  }
}

// vim: ts=2 sts=2

