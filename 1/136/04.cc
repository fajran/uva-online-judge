#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <algorithm>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

const int N = 1500;

int main() {
  set<long long> ugly;
  priority_queue<long long, vector<long long>, greater<long long> > q;
  q.push(1);

  long long num;
  int cnt = 0;
  while (!q.empty()) {
    num = q.top();
    q.pop();

    if (ugly.find(num) != ugly.end()) continue;
    ugly.insert(num);

    // printf("%lld ", num);
    cnt++;

    if (cnt == N) break;

    q.push(num * 2);
    q.push(num * 3);
    q.push(num * 5);
  }

  printf("The %d'th ugly number is %lld.\n", N, num);
}

// vim: ts=2 sts=2

