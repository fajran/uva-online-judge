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

using namespace std;

const int N = 1000;
int primes[N];

void gen() {
  primes[0] = 1;
  primes[1] = 2;

  int num = 2;
  for (int i=2; i<N; i++) {
    while (true) {
      num++;
      bool prime = true;
      for (int j=1; j<i && prime; j++) {
        int p = primes[j];
        if (num % p == 0) prime = false;
      }
      if (prime) {
        primes[i] = num;
        break;
      }
    }
  }
}

int main() {
  gen();
  while (true) {
    int n, c;
    cin >> n >> c;
    if (feof(stdin)) break;

    printf("%d %d:", n, c);

    int len = 0;
    for (int i=0; i<N; i++, len++) {
      if (primes[i] > n) break;
    }

    // printf(" len=%d", len);

    int start = 0;
    int end = len-1;

    if (len % 2 == 0) {
      start = len/2-c;
      end = len/2+c-1;
    }
    else {
      start = len/2-c+1;
      end = len/2+c-1;
    }

    if (start < 0) start = 0;
    if (end >= len) end = len-1;

    for (int i=start; i<=end; i++) {
      printf(" %d", primes[i]);
    }
    printf("\n\n");
  }
}

// vim: ts=2 sts=2

