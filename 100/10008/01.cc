#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

struct el {
  int cnt;
  int index;
};
vector<el> items;

bool cmp(el aa, el bb) {
  if (aa.cnt == bb.cnt)
    return aa.index > bb.index;
  return aa.cnt < bb.cnt;
}

int main() {
  for (int i=0; i<26; i++) {
    el item;
    item.cnt = 0;
    item.index = i;
    items.push_back(item);
  }

  int tc;
  string line;
  getline(cin, line);
  sscanf(line.c_str(), "%d", &tc);

  while (tc--) {
    getline(cin, line);

    const char *str = line.c_str();
    int len = line.length();

    for (int i=0; i<len; i++) {
      char ch = str[i];
      if (ch >= 'A' && ch <= 'Z')
        items[ch-'A'].cnt++;
      else if (ch >= 'a' && ch <= 'z')
        items[ch-'a'].cnt++;
    }
  }

  sort(items.begin(), items.end(), cmp);

  for (int i=26-1; i>=0; i--)
    if (items[i].cnt > 0) {
      printf("%c %d\n", items[i].index+'A', items[i].cnt);
    }
}

// vim: ts=2 sts=2

