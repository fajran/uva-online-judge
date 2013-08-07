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

using namespace std;

map<char, set<char> > edges;
set<char> nodes;

int main() {
  string line;
  getline(cin, line);

  int tc = atoi(line.c_str());
  getline(cin, line);
  assert(line.length() == 0);

  while (tc--) {
    edges.clear();
    nodes.clear();

    getline(cin, line);
    char max = line.c_str()[0];
    for (int i=0; i<=max-'A'; i++) {
      nodes.insert('A'+i);
      // printf("in: %c\n", 'A'+i);
    }

    while (true) {
      getline(cin, line);
      if (feof(stdin)) break;
      if (line.length() == 0) break;

      char src = line.c_str()[0];
      char dst = line.c_str()[1];

      nodes.insert(src);
      nodes.insert(dst);

      edges[src].insert(dst);
      edges[dst].insert(src);
    }

    int cnt = 0;
    while (nodes.size() > 0) {
      queue<char> q;
      char n = *(nodes.begin());
      q.push(n);
      nodes.erase(n);
      // printf("q: %c\n", n);

      while (q.size() > 0) {
        n = q.front();
        q.pop();

        set<char> nn = edges[n];
        set<char>::iterator ii;
        for (ii=nn.begin(); ii!=nn.end(); ii++) {
          char next = *ii;
          if (nodes.find(next) != nodes.end()) {
            q.push(next);
            nodes.erase(next);
          }
        }
      }

      cnt++;
    }

    printf("%d\n", cnt);
    if (tc > 0) printf("\n");
  }
}

// vim: ts=2 sts=2

