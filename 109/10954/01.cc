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

int main() {
  while (true) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;

    int num;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i=0; i<n; i++) {
      scanf("%d", &num);
      pq.push(num);
    }

    int ans = 0;
    while (pq.size() > 1) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      int c = a + b;
      ans += c;

      D("%d + %d = %d\n", a, b, c);

      pq.push(c);
    }
    printf("%d\n", ans);
  }
}

// vim: ts=2 sts=2

