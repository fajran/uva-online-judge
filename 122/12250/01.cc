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
#define D printf
#endif

using namespace std;

int main() {
  int tc = 0;
  char line[100];
  while (true) {
    scanf("%s", line);
    if (line[0] == '#') break;

    tc++;
#define P(s) printf("Case %d: " s "\n", tc)
    if      (!strcmp(line, "HELLO")) P("ENGLISH");
    else if (!strcmp(line, "HOLA")) P("SPANISH");
    else if (!strcmp(line, "HALLO")) P("GERMAN");
    else if (!strcmp(line, "BONJOUR")) P("FRENCH");
    else if (!strcmp(line, "CIAO")) P("ITALIAN");
    else if (!strcmp(line, "ZDRAVSTVUJTE")) P("RUSSIAN");
    else P("UNKNOWN");
  }
}

// vim: ts=2 sts=2

