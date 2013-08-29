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

#if defined(ONLINE_JUDGE) || !defined(DEBUG)
#define D(...)
#else
#define D printf
#endif

using namespace std;

const int MM = 15;

int W, H;
int N;

int xx[MM];
int yy[MM];
int dd[MM][MM];
bool vv[MM];
int path[MM];

bool found;
int ans;

inline int dist(int a, int b) {
  int dx = abs(xx[a] - xx[b]);
  int dy = abs(yy[a] - yy[b]);
  return dx + dy;
}

void find(int level, int cd) {
  if (level == N) {
    int prev = path[level-1];
    int nd = dd[prev][0];
    cd += nd;

    if (!found) ans = cd;
    else if (cd < ans) ans = cd;
    found = true;
    return;
  }

  for (int i=0; i<N; i++) {
    if (vv[i]) continue;

    int prev = path[level-1];
    int nd = dd[prev][i];

    if (found && cd+nd > ans) continue;

    vv[i] = true;
    path[level] = i;

    find(level+1, cd+nd);

    path[level] = -1;
    vv[i] = false;
  }
}

void go() {
  cin >> W >> H;
  cin >> xx[0] >> yy[0];
  cin >> N;
  N++;
  for (int i=1; i<N; i++) {
    cin >> xx[i] >> yy[i];
  }

  for (int i=0; i<N-1; i++) {
    for (int j=i+1; j<N; j++) {
      int d = dist(i, j);
      dd[i][j] = d;
      dd[j][i] = d;
    }
  }
  for (int i=0; i<N; i++) {
    vv[i] = false;
  }
  vv[0] = true;
  path[0] = 0;

  found = false;
  ans = 0;
  find(1, 0);
  printf("The shortest path has length %d\n", ans);
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    go();
  }
}

// vim: ts=2 sts=2

