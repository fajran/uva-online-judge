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

using namespace std;

map<long, long> FPOS;


int main() {
  {
    long a = 1;
    long b = 2;
    long p = 0;
    FPOS[a] = p++;
    FPOS[b] = p++;
    for (long i=0; i<1000; i++) {
      long c = a + b;
      FPOS[c] = p++;
      a = b;
      b = c;
      if (c < 0) break;
      // printf("fpos %ld -> %ld\n", c, FPOS[c]);
    }
  }

  string line;
  getline(cin, line);
  int tc = atoi(line.c_str());
  while (tc--) {
    getline(cin, line);
    int nums = atoi(line.c_str());

    getline(cin, line);
    stringstream sline(line);

    string ref;
    getline(cin, ref);

    map<long, char> fch;
    int cpos = 0;
    long max = 0;
    for (int i=0; i<nums; i++) {
      long n;
      sline >> n;

      char ch = ref[cpos++];
      while (ch < 'A' || ch > 'Z') {
        ch = ref[cpos++];
      }

      fch[n] = ch;
      // printf("- %d -> %c\n", n, ch);

      if (n > max) max = n;
    }

    int a = 1;
    int b = 2;

    char res[101];
    bzero(res, sizeof(res));

    {
      map<long, char>::iterator i;
      for (i=fch.begin(); i!=fch.end(); i++) {
        res[ FPOS[i->first] ] = i->second;
      }
    }

    {
      // printf("max: %d - %ld\n", max, FPOS.size());
      map<long, long>::iterator i;
      int x = 0;
      for (i=FPOS.begin(); i!=FPOS.end(); i++) {
        long n = i->first;
        if (n > max) break;
        if (fch.find(n) == fch.end()) {
          res[i->second] = ' ';
        }
      }
      // printf("\n");
    }

    printf("%s\n", res);
  }
}

// vim: ts=2 sts=2

