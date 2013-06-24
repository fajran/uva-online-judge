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

const int MM = 10000;

int main() {
  long nums[MM];
  bzero(nums, sizeof(nums));

  int len = 0;
  while (true) {
    long n;
    cin >> n;
    if (feof(stdin)) break;

    int pos = 0;
    for (int i=0; i<len; i++) {
      long num = nums[i];
      if (num > n) break;
      pos = i+1;
    }
    // printf("~pos: %d\n", pos);

    for (int i=len-1; i>=pos; i--)
      nums[i+1] = nums[i];

    nums[pos] = n;
    len++;

    // printf(" ->");
    // for (int i=0; i<len; i++)
    //   printf(" %ld", nums[i]);
    // printf("\n");

    if (len % 2 == 1) printf("%ld\n", nums[len/2]);
    else printf("%ld\n", (nums[len/2-1]+nums[len/2])/2);
  }
}

// vim: ts=2 sts=2

