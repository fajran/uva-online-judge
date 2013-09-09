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

const int MM = 1000 + 1;
const int MR = 10 + 1;
const int MOD = 1000;

int main() {
  string line;
  getline(cin, line);
  int tc = atoi(line.c_str());
  getline(cin, line); // blank

  int mem[MM];
  int reg[MR];

  while (tc--) {
    bzero(mem, sizeof(mem));
    bzero(reg, sizeof(reg));

    int len = 0;
    while (true) {
      getline(cin, line);
      if (feof(stdin) || line.length() == 0) break;

      mem[len++] = atoi(line.c_str());
    }
    if (len == 0) break;

    int pc = 0;
    int cnt = 0;
    bool halt = false;
    while (!halt) {
      int val = mem[pc++];

      int ins = (val / 100) % 10;
      int d = (val / 10) % 10;
      int s = val % 10;
      cnt++;

      D("%4d - %3d - %03d\n", cnt, pc-1, val);

      switch (ins) {
      case 1:
        halt = true;
        break;

      case 2:
        reg[d] = s;
        break;

      case 3:
        reg[d] = (reg[d] + s) % MOD;
        break;

      case 4:
        reg[d] = (reg[d] * s) % MOD;
        break;

      case 5:
        reg[d] = reg[s];
        break;

      case 6:
        reg[d] = (reg[d] + reg[s]) % MOD;
        break;

      case 7:
        reg[d] = (reg[d] * reg[s]) % MOD;
        break;

      case 8:
        reg[d] = mem[ reg[s] ] % MOD;
        break;

      case 9:
        mem[ reg[s] ] = reg[d] % MOD;
        break;

      case 0:
        if (reg[s] != 0) pc = reg[d] % MOD;
        break;
      }

#ifdef DEBUG
      D("->");
      for (int i=0; i<MR; i++) D(" %3d", reg[i]);
      D("\n");
#endif
    }

    printf("%d\n", cnt);
    if (tc > 0) printf("\n");
  }
}

// vim: ts=2 sts=2

