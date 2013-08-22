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

#define DEBUG

#if defined(ONLINE_JUDGE) || !defined(DEBUG)
#define D(...)
#else
#define D printf
#endif

using namespace std;

const int MM = 2001;

int N, M;

int conn[MM][MM];
int indeg[MM];
int outdeg[MM];
map<int, set<int> > edge;

void reset() {
  bzero(conn, sizeof(conn));
  bzero(indeg, sizeof(indeg));
  bzero(outdeg, sizeof(outdeg));
  edge.clear();
}

bool connected() {
  set<int> vv;
  queue<int> q;
  q.push(0);
  vv.insert(0);

  while (q.size() > 0) {
    int n = q.front();
    q.pop();

    set<int>::iterator ii, ee;
    for (ii=edge[n].begin(), ee=edge[n].end(); ii!=ee; ii++) {
      int nn = *ii;
      if (vv.find(nn) != vv.end()) continue;
      vv.insert(nn);
      q.push(nn);
    }
  }

  return vv.size() == N;
}

bool fully_connected() {
  for (int i=0; i<N; i++) {
    bool skip = false;
    for (int j=0; j<i; j++) {
      if (conn[i][j] && conn[j][i]) {
        skip = true;
        break;
      }
    }
    if (skip) continue;

    set<int> vv;
    queue<int> q;
    q.push(i);
    vv.insert(i);

    while (q.size() > 0) {
      int n = q.front();
      q.pop();

      set<int>::iterator ii, ee;
      for (ii=edge[n].begin(), ee=edge[n].end(); ii!=ee; ii++) {
        int nn = *ii;
        if (vv.find(nn) != vv.end()) continue;
        if (!conn[n][nn]) continue;
        vv.insert(nn);
        q.push(nn);
      }
    }

    if (vv.size() != N) return false;
  }

  return true;
}

void add_edge(int a, int b) {
  indeg[b]++;
  outdeg[a]++;
  conn[a][b] = 1;
  edge[a].insert(b);
  edge[b].insert(a);
}

int main() {
  // in degree > 0 && out degree > 0
  // all connected (assume undirected) -> flood fill
  while (true) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;

    reset();

    for (int i=0; i<M; i++) {
      int a, b, p;
      cin >> a >> b >> p;
      a--;
      b--;

      add_edge(a, b);
      if (p == 2) add_edge(b, a);
    }

    bool ok = true;
    for (int i=0; i<N; i++) {
      if (indeg[i] == 0 || outdeg[i] == 0) {
        D("deg fail %d -> in: %d, out %d\n", i, indeg[i], outdeg[i]);
        ok = false;
        goto end;
        break;
      }
    }

    if (!connected()) {
      ok = false;
      goto end;
    }

    ok = fully_connected();

end:
    printf("%d\n", ok ? 1 : 0);
  }
}

// vim: ts=2 sts=2

