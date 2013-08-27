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
#define DD
#define D printf
#endif

using namespace std;

const int MM = 100;
const int MOD = 1000000;

int find(int N, int K) {
  D("find N=%d, K=%d\n", N, K);
  int table[K+1][N+1];
  bzero(table, sizeof(table));

  for (int k=0; k<=K; k++) {
    for (int n=0; n<=N; n++) {
      if (k == 0) table[k][n] = 0;
      if (k == 1) table[k][n] = 1;
      if (n == 0) table[k][n] = 1;
      if (k > 1 && n > 0) {
        table[k][n] = (table[k][n-1] + table[k-1][n]) % MOD;
      }
    }
  }

#ifdef DD
  for (int k=1; k<=K; k++) {
    for (int n=0; n<=N; n++) {
      printf("%6d ", table[k][n]);
    }
    printf("\n");
  }
#endif

  return table[K][N];
}

int main() {
  while (true) {
    int N, K;
    cin >> N >> K;
    if (N == 0 && K == 0) break;
    int res = find(N, K);
    printf("%d\n", res % MOD);
  }
}

// vim: ts=2 sts=2

