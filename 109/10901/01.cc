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

const int MM = 10001;
int N, T, M;

enum Side {
  L, R, SS
};

struct Car {
  int t;
  int s;
  int a;
};
Car cars[MM];

queue<int> qcar[SS];
queue<int> qall;

void read() {
  scanf("%d %d %d", &N, &T, &M);
  int t;
  char side[10];

  for (int i=0; i<SS; i++) {
    while (!qcar[i].empty()) {
      qcar[i].pop();
    }
  }
  while (!qall.empty()) {
    qall.pop();
  }

  for (int i=0; i<M; i++) {
    scanf("%d %s", &t, side);
    cars[i].t = t;
    int s = side[0] == 'l' ? L : R;
    cars[i].s = s;
    qcar[s].push(i);
    qall.push(i);
  }

  D("q left %lu right %lu\n", qcar[L].size(), qcar[R].size());
}

void sim() {
  int now = 0;
  int bside = L;
  vector<int> in;

  while (true) {
    D("-> Now is %d, side at %d, left %lu, right %lu\n", now, bside, qcar[L].size(), qcar[R].size());
    if (qcar[L].empty() && qcar[R].empty() && in.size() == 0) {
      D("Done!\n");
      break;
    }

    // check current side
    int next[SS];
    next[L] = -1;
    next[R] = -1;

    // check current side, if there is space left
    if (!qcar[bside].empty() && in.size() < N) {
      int c = qcar[bside].front();
      if (cars[c].t <= now) {
        D("   Load a car %d, from %d, at %d\n", c, bside, now);
        // load a car
        in.push_back(c);
        qcar[bside].pop();
        continue;
      }
      next[bside] = cars[c].t;
    }
    else {
      D("   No car on the current side, from %d\n", bside);
    }

    // move what we have to the other side
    if (in.size() > 0) {
      D("   Carry %lu cargo, from %d to %d, at %d to %d\n", in.size(), bside, R - bside, now, now+T);

      now += T; // travel to the other side
      bside = R - bside;
      for (int i=0; i<in.size(); i++) {
        int c = in[i];
        cars[c].a = now;
      }
      in.clear(); // unload
      continue;
    }

    // check other side
    int os = R - bside;
    if (!qcar[os].empty()) {
      int c = qcar[os].front();
      if (cars[c].t <= now) {
        D("   Car waiting on the other side, from %d, at %d to %d\n", bside, now, now+T);
        // travel to other side
        now += T;
        bside = os;
        continue;
      }
      next[os] = cars[c].t;
    }
    else {
      D("   No car on the other side either!\n");
    }

    // advance to the next arrival
    if (next[L] != -1 && next[R] != -1) {
      if (next[bside] < next[os]) {
        D("   Advance to the next arrival, from %d, at %d\n", bside, next[bside]);
        now = next[bside];
        continue;
      }
      else {
        D("   Advance to the next arrival on the other side, from %d, at %d to %d\n", os, next[os], next[os] + T);
        now = next[os];
        now += T;
        bside = R - bside;
      }
    }
    else if (next[bside] != -1) {
      D("   Advance to the next arrival, from %d, at %d\n", bside, next[bside]);
      now = next[bside];
      continue;
    }
    else if (next[os] != -1) {
      D("   Advance to the next arrival on the other side, from %d, at %d to %d\n", os, next[os], next[os] + T);
      now = next[os];
      now += T;
      bside = R - bside;
    }
    else {
      D("!! PANIC! %d %d\n", next[L], next[R]);
      return;
    }
  }
}

void out() {
  for (int i=0; i<M; i++) {
    printf("%d\n", cars[i].a);
  }
}

void go() {
  read();
  sim();
  out();
}


int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    go();
    if (tc > 0) printf("\n");
  }
}

// vim: ts=2 sts=2

