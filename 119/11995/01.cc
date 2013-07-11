#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
  while (true) {
    int line;
    cin >> line;
    if (feof(stdin)) break;

    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    bool ss, qq, pqq;
    ss = true;
    qq = true;
    pqq = true;

    for (int i=0; i<line; i++) {
      int a, b;
      cin >> a >> b;
      if (a == 1) {
        s.push(b);
        q.push(b);
        pq.push(b);
      }
      else {
        if (s.size() == 0) {
          ss = false;
        }
        else {
          if (b != s.top()) {
            ss = false;
          }
          s.pop();
        }

        if (q.size() == 0) {
          qq = false;
        }
        else {
          if (b != q.front()) {
            qq = false;
          }
          q.pop();
        }

        if (pq.size() == 0) {
          pqq = false;
        }
        else {
          if (b != pq.top()) {
            pqq = false;
          }
          pq.pop();
        }
      }
    }
    if (ss && !qq && !pqq)
      printf("stack\n");
    else if (!ss && qq && !pqq)
      printf("queue\n");
    else if (!ss && !qq && pqq)
      printf("priority queue\n");
    else if (!ss && !qq && !pqq)
      printf("impossible\n");
    else
      printf("not sure\n");
  }
}

// vim: ts=2 sts=2

