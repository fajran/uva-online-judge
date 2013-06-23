#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

const int MM = 200;

struct Node {
  int color;
  set<int> next;

  Node() : color(-1) {}

  void reset() {
    color = -1;
    next.clear();
  }
};

Node *nodes[MM];

int main() {
  for (int i=0; i<MM; i++) {
    nodes[i] = new Node();
  }

  while (true) {
    int nnode;
    cin >> nnode;
    if (nnode == 0) break;
    int nedge;
    cin >> nedge;

    for (int i=0; i<MM; i++) {
      nodes[i]->reset();
    }

    for (int i=0; i<nedge; i++) {
      int a, b;
      cin >> a >> b;
      nodes[a]->next.insert(b);
      nodes[b]->next.insert(a);
    }

    queue<int> q;
    nodes[0]->color = 1;
    q.push(0);

    bool ok = true;
    while (ok && q.size() > 0) {
      int n = q.front();
      q.pop();

      Node *nn = nodes[n];
      int c = nn->color;

      set<int>::iterator it;
      for (it=nn->next.begin(); it!=nn->next.end(); it++) {
        int next = *it;
        Node *x = nodes[next];
        if (x->color == -1) {
          x->color = 1 - c;
          q.push(next);
        }
        else if (x->color == c) {
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      printf("BICOLORABLE.\n");
    }
    else {
      printf("NOT BICOLORABLE.\n");
    }
  }
}

// vim: ts=2 sts=2

