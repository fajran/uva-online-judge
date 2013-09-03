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

struct Col;
struct Row;

struct Col {
  int num;
  int value;
};

struct Row {
  int num;
  map<int, Col*> cols;
  vector<int> colList;
};

map<int, Row*> rows;
vector<int> rowList;

int R, C;

void put(int i, int j, int val) {
  int r = j;
  int c = i;

  Row* row;
  if (rows.find(r) == rows.end()) {
    row = new Row();
    row->num = r;
    rows[r] = row;
    rowList.push_back(r);
  }
  else {
    row = rows[r];
  }

  Col* col;
  if (row->cols.find(c) == row->cols.end()) {
    col = new Col();
    col->num = c;
    row->cols[c] = col;
    row->colList.push_back(c);
  }
  else {
    col = row->cols[c];
  }

  col->value = val;
}

int main() {
  scanf("%d %d", &R, &C);
  for (int i=0; i<R; i++) {
    int n;
    scanf("%d", &n);
    if (n == 0) continue;
    int p[n];
    for (int j=0; j<n; j++) {
      scanf("%d", &p[j]);
    }
    for (int j=0; j<n; j++) {
      int val;
      scanf("%d", &val);
      put(i, p[j], val);
    }
  }

  printf("%d %d\n", C, R);
  sort(rowList.begin(), rowList.end());
  int p = 1;
  for (int i=0, _i=rowList.size(); i<_i; i++, p++) {
    int r = rowList[i];
    while (p < r) {
      printf("0\n\n");
      p++;
    }

    Row* row = rows[r];
    sort(row->colList.begin(), row->colList.end());

    int nc = row->colList.size();
    int cols[nc];
    int vals[nc];
    for (int j=0; j<nc; j++) {
      int c = row->colList[j];
      Col* col = row->cols[c];
      cols[j] = col->num;
      vals[j] = col->value;
    }

    printf("%d", nc);
    for (int j=0; j<nc; j++) printf(" %d", cols[j]+1);
    printf("\n");
    printf("%d", vals[0]);
    for (int j=1; j<nc; j++) printf(" %d", vals[j]);
    printf("\n");
  }
  while (p <= C) {
    printf("0\n\n");
    p++;
  }
}

// vim: ts=2 sts=2

