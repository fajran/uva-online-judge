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

struct D {
  string orig;
  string s;
};

string simplify(string& s) {
  string c(s.begin(), s.end());
  char* str = (char*)c.c_str();
  int i, j, len;
  for (i=0, j=0, len=s.length(); i<len; i++) {
    char ch = str[i];
    if (ch > ' ') {
      str[j++] = ch;
    }
  }
  str[j] = 0;
  sort(str, str+j);
  return string(str);
}

bool cmpdata(D* a, D* b) {
  return a->s < b->s;
}

void perm(vector<string>& values) {
  int len = values.size();
  for (int i=0; i<len-1; i++) {
    for (int j=i+1; j<len; j++) {
      cout << values[i] << " = " << values[j] << endl;
    }
  }
}

int main() {
  string line;
  getline(cin, line);
  int tc = atoi(line.c_str());
  getline(cin, line); // first blank
  for (int tt=0; tt<tc; tt++) {
    vector<D*> data;

    while (true) {
      getline(cin, line);
      if (line == "" || feof(stdin)) break;

      D* d = new D;
      d->orig = line;
      d->s = simplify(line);
      data.push_back(d);
    }

    sort(data.begin(), data.end(), cmpdata);

    map<string, set<string> > g;
    set<string> keys;
    for (int i=0, len=data.size(); i<len; i++) {
      g[data[i]->s].insert(data[i]->orig);
      keys.insert(data[i]->s);
      delete data[i];
    }

    vector<string> vkeys(keys.begin(), keys.end());
    sort(vkeys.begin(), vkeys.end());

    if (tt > 0) printf("\n");

    for (int i=0, len=vkeys.size(); i<len; i++) {
      string k = vkeys[i];
      if (g[k].size() > 0) {
        vector<string> values(g[k].begin(), g[k].end());
        perm(values);
      }
    }

    if (feof(stdin)) break;
  }
}

// vim: ts=2 sts=2

