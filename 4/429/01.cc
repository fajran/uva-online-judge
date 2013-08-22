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

#define DEBUG

#if defined(ONLINE_JUDGE) || !defined(DEBUG)
#define D(...)
#else
#define D printf
#endif

using namespace std;

int cword = 0;
map<string, int> windex;
map<int, string> wtext;
map<int, set<int> > wnext;

void reset() {
  cword = 0;
  windex.clear();
  wtext.clear();
  wnext.clear();
}

void set_next(int a, int b) {
  wnext[a].insert(b);
  wnext[b].insert(a);
}

bool is_next(string a, string b) {
  int na = a.length();
  int nb = b.length();
  if (na != nb) return false;

  const char* aa = a.c_str();
  const char* bb = b.c_str();

  int cnt = 0;
  for (int i=0; i<na; i++) {
    if (aa[i] != bb[i]) {
      cnt++;
      if (cnt > 1) return false;
    }
  }

  return true;
}

void add_word(string word) {
  int index = cword++;
  wtext[index] = word;
  windex[word] = index;

  // printf("w: %s\n", word.c_str());

  for (int i=0; i<index; i++) {
    if (is_next(wtext[i], word)) {
      // printf("-> next: %s %s\n", wtext[i].c_str(), word.c_str());
      set_next(i, index);
    }
  }
}

typedef pair<int, int> pp;
int get_distance(int a, int b) {
  int d = 0;
  queue<pp> q;
  q.push(make_pair(a, 0));

  set<int> visited;

  while (q.size() > 0) {
    pp nn = q.front();
    q.pop();

    int n = nn.first;
    visited.insert(n);

    set<int>::iterator ii;
    for (ii=wnext[n].begin(); ii!=wnext[n].end(); ii++) {
      int x = *ii;
      if (visited.find(x) != visited.end()) continue;
      if (x == b) return nn.second+1;
      q.push(make_pair(x, nn.second+1));
    }
  }

  assert(false);
  return -1;
}

int find(string a, string b) {
  int ia = windex[a];
  int ib = windex[b];
  return get_distance(ia, ib);
}

int main() {
  string line;
  getline(cin, line);
  int tc = atoi(line.c_str());

  reset();

  getline(cin, line); // blank line
  for (int tt=0; tt<tc; tt++) {
    if (tt>0) printf("\n");

    bool cw = true;
    while (true) {
      getline(cin, line);
      if (line == "*") {
        cw = false;
      }
      else if (line.length() == 0) {
        // set separator
        break;
      }
      else {
        if (cw) add_word(line);
        else {
          stringstream ss(line);
          string a, b;
          ss >> a;
          ss >> b;
          int len = find(a, b);
          cout << a << " " << b << " " << len << endl;
        }
      }
    }
  }
}

// vim: ts=2 sts=2

