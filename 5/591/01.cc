#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DEBUG

#if defined(ONLINE_JUDGE) || !defined(DEBUG)
#define D(...)
#else
#define D printf
#endif


using namespace std;

int main() {
  int n, num;
  int tc = 0;
  while (true) {
    cin >> n;
    if (n == 0) break;
    tc++;

    int arr[n];
    int sum = 0;
    for (int i=0; i<n; i++) {
      cin >> num;
      sum += num;
      arr[i] = num;
    }

    int avg = sum / n;
    sum = 0;
    for (int i=0; i<n; i++) {
      sum += abs(arr[i] - avg);
    }

    printf("Set #%d\n", tc);
    printf("The minimum number of moves is %d.\n", sum/2);
    printf("\n");
  }
}

// vim: ts=2 sts=2

