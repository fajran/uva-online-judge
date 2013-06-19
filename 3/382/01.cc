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
  printf("PERFECTION OUTPUT\n");
  while (true) {
    int num;
    cin >> num;
    if (num == 0) break;

    int sum = 0;
    for (int i=1; i<num; i++) {
      if (num % i == 0) sum += i;
    }

    printf("%5d  ", num);
    if (sum == num) {
      printf("PERFECT\n");
    }
    else if (sum < num) {
      printf("DEFICIENT\n");
    }
    else {
      printf("ABUNDANT\n");
    }
  }
  printf("END OF OUTPUT\n");
}

// vim: ts=2 sts=2

