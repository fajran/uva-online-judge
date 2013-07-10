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

using namespace std;

int N, M;

char *A;
char *B;

#define VA(i, j) A[(i)*N+(j)]
#define VB(i, j) B[(i)*M+(j)]
#define VT(i, j) T[(i)*M+(j)];

void rotate() {
  char T[M*M];
  memcpy(T, B, sizeof(char)*M*M);
  int mm = M-1;
  for (int i=0; i<M; i++) {
    for (int j=0; j<M; j++) {
      VB(j, mm-i) = VT(i, j);
    }
  }
}

void P(char *d, int n) {
  int ii = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      printf("%c", d[i*n+j]);
    }
    printf("\n");
  }
}

int go() {
  // P(A, N);
  // P(B, M);

  // printf("%c %c\n", VA(1,0), VB(1,0));

  // return -1;

  int s = N-M+1;
  int cnt = 0;
  for (int i=0; i<s; i++) {
    for (int j=0; j<s; j++) {
      bool found = true;
      for (int aa=0; aa<M && found; aa++)
        for (int bb=0; bb<M && found; bb++) {
          // printf("-- (%d,%d)->(%d,%d): %c %c\n", i, j, aa, bb, VB(aa,bb), VA(aa+i, bb+j));
          if (VB(aa,bb) != VA(aa+i,bb+j))
            found = false;
        }
      if (found) {
        cnt += 1;
        // printf("~ %d %d\n", i, j);
      }
    }
  }
  return cnt;
}

int main() {
  while (true) {
    string line;
    getline(cin, line);
    sscanf(line.c_str(), "%d %d", &N, &M);
    if (N == 0 && M == 0) break;

    A = new char[N*N];
    B = new char[M*M];

    for (int i=0; i<N; i++) {
      getline(cin, line);
      const char *s = line.c_str();
      for (int j=0; j<N; j++) {
        VA(i, j) = s[j];
      }
    }
    for (int i=0; i<M; i++) {
      getline(cin, line);
      const char *s = line.c_str();
      for (int j=0; j<M; j++) {
        VB(i, j) = s[j];
      }
    }

    for (int i=0; i<4; i++) {
      int cnt = go();
      if (i>0) printf(" ");
      printf("%d", cnt);
      rotate();
    }
    printf("\n");

    delete A;
    delete B;
  }
}

// vim: ts=2 sts=2

