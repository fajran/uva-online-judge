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

const int MN = 25;

int N;
char A[MN];
char B[MN];
int ANS;

int idx;
int gi;
map<string, int> ids;
map<int, int> group;
map<int, int> cmem;
map<int, int> parent;
map<int, int> root;
map<int, set<int> > groups;

void reset() {
  idx = 0;
  gi = 0;
  ids.clear();
  group.clear();
  cmem.clear();
  parent.clear();
  root.clear();
  groups.clear();
}

void add() {
  string a(A);
  string b(B);
  if (ids.find(a) == ids.end()) {
    ids[a] = idx;
    group[idx] = gi;
    parent[gi] = gi;
    cmem[gi] = 1;
    root[gi] = gi;
    gi++;
    idx++;
  }
  if (ids.find(b) == ids.end()) {
    ids[b] = idx;
    group[idx] = gi;
    parent[gi] = gi;
    cmem[gi] = 1;
    root[gi] = gi;
    gi++;
    idx++;
  }

  int ida = ids[a];
  int idb = ids[b];
  int ga = group[ida];
  int gb = group[idb];
  int ra = root[ga];
  int rb = root[gb];

  parent[ra] = gb;
  root[ra] = rb;
  cmem[rb] += cmem[ra];

  ANS = cmem[rb];
}

void go() {
  reset();
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%s %s", A, B);
    add();
    printf("%d\n", ANS);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) go();
}

// vim: ts=2 sts=2

