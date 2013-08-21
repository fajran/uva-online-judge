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

const int MM = 100;

int N;
map<int, set<int> > edges;

void reset() {
  edges.clear();
}

void add_edge(int a, int b) {
  edges[a].insert(b);
  edges[b].insert(a);
}

bool connected(int d) {
  int visited[N+1];
  bzero(visited, sizeof(visited));

  int s = 1;
  if (s == d) s = N;

  queue<int> q;
  q.push(s);
  while (q.size() > 0) {
    int n = q.front();
    q.pop();

    visited[n] = 1;

    set<int>::iterator ii = edges[n].begin();
    for (; ii != edges[n].end(); ii++) {
      int nn = *ii;
      if (nn == d) continue;
      if (visited[nn] > 0) continue;
      q.push(nn);
    }
  }

  for (int i=1; i<=N; i++)
    if (visited[i] == 0 && i != d) return false;
  return true;
}

int get_criticals() {
  int cnt = 0;

  for (int i=1; i<=N; i++) {
    int d = i;
    if (!connected(d)) cnt++;
  }

  return cnt;
}

int main() {
  string line;
  while (true) {
    getline(cin, line);
    N = atoi(line.c_str());
    if (N == 0) break;

    reset();

    while (true) {
      getline(cin, line);
      stringstream ss(line);

      int p;
      ss >> p;
      if (p == 0) break;
      while (!ss.eof()) {
        int nn;
        ss >> nn;

        add_edge(p, nn);
      }
    }

    int cc = get_criticals();
    printf("%d\n", cc);
  }
}

// vim: ts=2 sts=2

