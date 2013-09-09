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

const int ML = 5;
const int MM = 10000;

int _size(int level) {
  int s = 32;
  while (level--) s = s / 2;
  return s * s;
}

int size[ML];
char A[MM];
char B[MM];
int LA, LB;

void pop(char* s, int* p) {
  D("pop(%p)\n", s);
  int c = 4;
  while (c--) {
    if (s[*p] == 'p') c += 4;
    *p = *p + 1;
  }
}

int count(char* s, int* p, int level) {
  D("count(%p) p: %d, level: %d\n", s, *p, level);
  int cnt = 0;
  int idx[ML];
  bzero(idx, sizeof(idx));
  int l = level;
  while (l >= level) {
    char c = s[*p];
    idx[l]++;

    if (c == 'p') {
      *p = *p + 1;
      l++;
    }
    else if (c == 'e') {
      *p = *p + 1;
    }
    else {
      *p = *p + 1;
      cnt += size[l];
    }

    if (idx[l] == 4) l--;
  }

  D("-> %d\n", cnt);
  return cnt;
}

void go() {
  scanf("%s", A);
  scanf("%s", B);
  LA = strlen(A);
  LB = strlen(B);

  D("&A: %p, &B: %p\n", A, B);

  int pa = 0;
  int pb = 0;
  int cnt = 0;
  int level = 0;
  int idx[ML];
  bzero(idx, sizeof(idx));

  while (pa < LA) {
    D("\npa: %d, len: %d - pb: %d, len: %d\n", pa, LA, pb, LB);
    char ca = A[pa];
    char cb = B[pb];
    idx[level]++;

    if (ca == 'e' && cb == 'e') {
      pa++; pb++;
      D("e - e\n");
    }
    else if (ca == 'f' && cb == 'f') {
      pa++; pb++;
      cnt += size[level];
      D("f - f - level: %d, s: %d\n", level, size[level]);
    }
    else if (ca == 'p' && cb == 'p') {
      pa++; pb++;
      level++;
      D("p - p - level: %d\n", level);
    }
    else if (ca == 'p' && cb == 'f') {
      pa++; pb++;
      cnt += size[level];
      pop(A, &pa);
      D("p - f - level: %d, s: %d\n", level, size[level]);
    }
    else if (cb == 'f' && cb == 'p') {
      pa++; pb++;
      cnt += size[level];
      pop(B, &pb);
      D("f - p - level: %d, s: %d\n", level, size[level]);
    }
    else if (ca == 'p' && cb == 'e') {
      pa++; pb++;
      cnt += count(A, &pa, level+1);
    }
    else if (ca == 'e' && cb == 'p') {
      pa++; pb++;
      cnt += count(B, &pb, level+1);
    }
    else { // ca == 'f' || cb == 'f'
      pa++; pb++;
      cnt += size[level];
    }

    if (idx[level] == 4) {
      level--;
    }
  }

  printf("There are %d black pixels.\n", cnt);
}

int main() {
  for (int i=0; i<ML; i++) size[i] = _size(i);
  int tc;
  scanf("%d", &tc);
  while (tc--) go();
}

// vim: ts=2 sts=2

