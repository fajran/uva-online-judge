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
  string line;
  while (true) {
    getline(cin, line);
    int len = line.length();
    const char *str = line.c_str();

    if (len == 1 && str[0] == '0') break;

    long long num = 0;
    long long m = 1L << len;
    for (int i=0, j=len-1; i<len; i++, j--) {
      long long d = str[i] - '0';
      num += d * (m - 1);
      m = m >> 1;
    }

    printf("%lld\n", num);
  }
}

// vim: ts=2 sts=2

