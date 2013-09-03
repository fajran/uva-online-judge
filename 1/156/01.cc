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

string basic(char* str, int len) {
  vector<char> v;
  for (int i=0; i<len; i++) {
    char ch = str[i];
    if (ch >= 'a') ch = ch - 'a' + 'A';
    v.push_back(ch);
  }
  sort(v.begin(), v.end());
  char res[len+1];
  for (int i=0; i<len; i++) {
    res[i] = v[i];
  }
  res[len] = 0;
  return string(res);
}

int main() {
  char word[21];
  map<string, string> orig;
  map<string, int> cnt;

  while (true) {
    scanf("%s", word);
    if (feof(stdin)) break;
    string s(word);
    if (s == "#") break;
    string b = basic(word, s.length());
    // cout << s << " -> " << b << endl;

    cnt[b] += 1;
    orig[b] = s;
  }

  vector<string> res;
  for (map<string, int>::iterator ii=cnt.begin(); ii!=cnt.end(); ii++) {
    if (ii->second == 1) {
      res.push_back(orig[ii->first]);
    }
  }
  sort(res.begin(), res.end());
  for (int i=0; i<res.size(); i++) {
    cout << res[i] << endl;
  }
}

// vim: ts=2 sts=2

